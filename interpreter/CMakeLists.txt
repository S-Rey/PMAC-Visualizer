cmake_minimum_required(VERSION 2.8)

project("PMAC-Interpreter")

# CMake commands copied by the CMake file for CImg

# To use PKG_CHECK_MODULES to find some optional packages
find_package(PkgConfig)

### Not sure yet if it is useful ###
if(NOT WIN32)
  #FIND_PACKAGE(X11)
  FIND_PACKAGE(Threads REQUIRED)
endif()
####################################

if (NOT WIN32)
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${CMAKE_THREAD_LIBS_INIT} )
endif()

set(antlr4-tutorial-GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACLexer.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACParser.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACVisitor.cpp
 )

foreach( src_file ${antlr4-tutorial-GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${antlr4-tutorial-GENERATED_SRC} )

include_directories(
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/misc
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/atn
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/dfa
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/tree
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/support
  ${PROJECT_SOURCE_DIR}/
  ${PROJECT_SOURCE_DIR}/libs/
  )

set(antlr4-tutorial_SRC
  ${PROJECT_SOURCE_DIR}/interpreter.cpp
  ${PROJECT_SOURCE_DIR}/Visitor.cpp
  ${PROJECT_SOURCE_DIR}/Environment.cpp
  ${antlr4-tutorial-GENERATED_SRC}
  )

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${antlr4-tutorial_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach( src_file ${antlr4-tutorial_SRC} )

add_executable(antlr4-tutorial
  ${antlr4-tutorial_SRC}
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  # see https://github.com/antlr/antlr4/issues/1874
  target_compile_options(antlr4-tutorial PUBLIC "$<$<CONFIG:DEBUG>:/MT>")
endif()

if(WIN32)
  target_link_libraries(antlr4-tutorial "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(antlr4-tutorial "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(antlr4-tutorial "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")
endif()

target_link_libraries(antlr4-tutorial ${SYSTEM_LIBS})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_custom_command(TARGET antlr4-tutorial POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so"
  $<TARGET_FILE_DIR:antlr4-tutorial>)
endif()

if(WIN32)
add_custom_command(TARGET antlr4-tutorial POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dll"
  $<TARGET_FILE_DIR:antlr4-tutorial>)
endif()

if(APPLE)
add_custom_command(TARGET antlr4-tutorial POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dylib"
  $<TARGET_FILE_DIR:antlr4-tutorial>)
endif()

# copy the input file next to the generated executable
add_custom_command(TARGET antlr4-tutorial POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/input.PMAC"
  $<TARGET_FILE_DIR:antlr4-tutorial>)

# necessary because the default working directory of Visual Studio
# is not the same as the one in which the binary is created
# so we copy the input file twice:
# one for when you launch the executale in Visual Studio (CTRL+F5)
# one for when you launch it normally
if (WIN32)
add_custom_command(TARGET antlr4-tutorial POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/input.PMAC"
  $<TARGET_FILE_DIR:antlr4-tutorial>/../)
endif()
