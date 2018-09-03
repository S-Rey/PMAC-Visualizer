cmake_minimum_required (VERSION 2.8.3)

project("PMAC-Visualizer")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")


### Generated source by antlr
set(GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/PMACLexer.cpp
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/PMACParser.cpp
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/PMACBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/PMACVisitor.cpp
)
foreach( src_file ${GENERATED_SRC} )
    set_source_files_properties(
        ${src_file}
        PROPERTIES
        GENERATED TRUE
    )
endforeach( src_file ${GENERATED_SRC} )
include_directories(
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/misc
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/atn
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/dfa
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/tree
  ${PROJECT_SOURCE_DIR}/interpreter/antlr4-runtime/support
  ${PROJECT_SOURCE_DIR}/interpreter/
  ${PROJECT_SOURCE_DIR}/interpreter/libs/
  ${PROJECT_SOURCE_DIR}/interpreter/include
)
set(PMAC-Interpreter_SRC
    # Header files
    interpreter/include/interpreter/Environment.h
    interpreter/include/interpreter/Visitor.h

    # Source files
    interpreter/src/Environment.cpp
    interpreter/src/Visitor.cpp
    ${GENERATED_SRC}
)
if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set (flags_1 "-Wno-overloaded-virtual")
else()
    set (flags_1 "-MP /wd4251")
endif()


add_subdirectory(visualizer/ext visualizer/ext_build)

include_directories(
  # Nori include files
  ${CMAKE_CURRENT_SOURCE_DIR}/visualizer/include
  ${GLFW_INCLUDE_DIR}
  # GLEW library for accessing OpenGL functions
  ${GLEW_INCLUDE_DIR}
  # NanoVG drawing library
  ${NANOVG_INCLUDE_DIR}
  # NanoGUI user interface library
  ${NANOGUI_INCLUDE_DIR}
  ${NANOGUI_EXTRA_INCS}
)

add_executable(PMAC-Visualizer
    ${PMAC-Interpreter_SRC}
    # Header files
    visualizer/include/visualizer/grid.h
    visualizer/include/visualizer/PMACVisualizerApplication.h

    # Source files
    #src/grid.cpp
    visualizer/src/PMACVisualizerApplication.cpp
    src/main.cpp
)

add_definitions(${NANOGUI_EXTRA_DEFS})

target_link_libraries(PMAC-Visualizer nanogui ${NANOGUI_EXTRA_LIBS})


### Link antlr libraries for WIN, MAC and UNIX Platform
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  # see https://github.com/antlr/antlr4/issues/1874
  target_compile_options(PMAC-Visualizer PUBLIC "$<$<CONFIG:DEBUG>:/MT>")
endif()

if(WIN32)
  target_link_libraries(PMAC-Visualizer "${PROJECT_SOURCE_DIR}/interpreter/libs/antlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(PMAC-Visualizer "${PROJECT_SOURCE_DIR}/interpreter/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(PMAC-Visualizer "${PROJECT_SOURCE_DIR}/interpreter/libs/libantlr4-runtime.so")
endif()

target_link_libraries(PMAC-Visualizer ${SYSTEM_LIBS})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_custom_command(TARGET PMAC-Visualizer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/interpreter/libs/libantlr4-runtime.so"
  $<TARGET_FILE_DIR:PMAC-Visualizer>)
endif()

if(WIN32)
add_custom_command(TARGET PMAC-Visualizer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/interpreter/libs/antlr4-runtime.dll"
  $<TARGET_FILE_DIR:PMAC-Visualizer>)
endif()

if(APPLE)
add_custom_command(TARGET PMAC-Visualizer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/interpreter/libs/antlr4-runtime.dylib"
  $<TARGET_FILE_DIR:PMAC-Visualizer>)
endif()

# copy the input file next to the generated executable
add_custom_command(TARGET PMAC-Visualizer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/interpreter/input.PMAC"
  $<TARGET_FILE_DIR:PMAC-Visualizer>)

# necessary because the default working directory of Visual Studio
# is not the same as the one in which the binary is created
# so we copy the input file twice:
# one for when you launch the executale in Visual Studio (CTRL+F5)
# one for when you launch it normally
if (WIN32)
add_custom_command(TARGET PMAC-Visualizer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/interpreter/input.PMAC"
  $<TARGET_FILE_DIR:PMAC-Visualizer>/../)
endif()
