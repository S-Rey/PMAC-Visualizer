cmake_minimum_required (VERSION 2.8.3)

project("PMAC-Visualizer")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

add_subdirectory(ext ext_build)


include_directories(
  # Nori include files
  ${CMAKE_CURRENT_SOURCE_DIR}/include
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
    # Header files

    # Source files
    src/main.cpp
)

add_definitions(${NANOGUI_EXTRA_DEFS})

target_link_libraries(PMAC-Visualizer nanogui ${NANOGUI_EXTRA_LIBS})
