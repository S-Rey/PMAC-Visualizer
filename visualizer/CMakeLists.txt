cmake_minimum_required (VERSION 2.8.3)

project("PMAC-Visualizer")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

add_subdirectory(ext)

add_executable(visualizer
    # Header files

    # Source files
    src/main.cpp
    )

target_include_directories(visualizer PRIVATE
    # Visualizer include files
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    # Eigen linear algebra library
    ${GLFW_INCLUDE_DIR}
    # GLAD OpenGL function loader
    ${GLAD_INCLUDE_DIR}
    # TinyObjLoader OBJ mesh loader
    )

target_link_libraries(visualizer glfw glad ${CMAKE_THREAD_LIBS_INIT})


