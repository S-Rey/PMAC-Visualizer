cmake_minimum_required(VERSION 2.8)
project("PMAC-Interpreter")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

## Generated source by antlr
set(GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACLexer.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACParser.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/PMACVisitor.cpp
)

foreach( src_file ${GENERATED_SRC} )
    set_source_files_properties(
        ${src_file}
        PROPERTIES
        GENERATED TRUE
    )
endforeach( src_file ${GENERATED_SRC} )

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


set(PMAC-Interpreter_SRC
    # Header files
    include/interpreter/Environment.h
    include/interpreter/Visitor.h

    # Source files
    src/Environment.cpp
    src/Visitor.cpp
    ${GENERATED_SRC}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set (flags_1 "-Wno-overloaded-virtual")
else()
    set (flags_1 "-MP /wd4251")
endif()

###### Executable
add_executable(PMAC-Interpreter
    src/interpreter.cpp
    ${PMAC-Interpreter_SRC}
)
target_include_directories(PMAC-Interpreter PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

###### GTEST
add_subdirectory(ext/googletest)

add_executable(PMAC-Interpreter-tests
    test/main.cpp
    ${PMAC-Interpreter_SRC}
)
target_include_directories(PMAC-Interpreter-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  # see https://github.com/antlr/antlr4/issues/1874
  target_compile_options(PMAC-Interpreter PUBLIC "$<$<CONFIG:DEBUG>:/MT>")
  target_compile_options(PMAC-Interpreter-tests PUBLIC "$<$<CONFIG:DEBUG>:/MT>")
endif()

if(WIN32)
  target_link_libraries(PMAC-Interpreter "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.lib")
  target_link_libraries(PMAC-Interpreter-tests "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(PMAC-Interpreter "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
  target_link_libraries(PMAC-Interpreter-tests "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(PMAC-Interpreter "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")
  target_link_libraries(PMAC-Interpreter-tests "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")
endif()


target_link_libraries(PMAC-Interpreter ${SYSTEM_LIBS})
target_link_libraries(PMAC-Interpreter-tests gtest ${SYSTEM_LIBS})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_custom_command(TARGET PMAC-Interpreter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so"
  $<TARGET_FILE_DIR:PMAC-Interpreter>)
endif()

if(WIN32)
add_custom_command(TARGET PMAC-Interpreter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dll"
  $<TARGET_FILE_DIR:PMAC-Interpreter>)
endif()

if(APPLE)
add_custom_command(TARGET PMAC-Interpreter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dylib"
  $<TARGET_FILE_DIR:PMAC-Interpreter>)
endif()

# copy the input file next to the generated executable
add_custom_command(TARGET PMAC-Interpreter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/input.PMAC"
  $<TARGET_FILE_DIR:PMAC-Interpreter>)

# necessary because the default working directory of Visual Studio
# is not the same as the one in which the binary is created
# so we copy the input file twice:
# one for when you launch the executale in Visual Studio (CTRL+F5)
# one for when you launch it normally
if (WIN32)
add_custom_command(TARGET PMAC-Interpreter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/input.PMAC"
  $<TARGET_FILE_DIR:PMAC-Interpreter>/../)
endif()
