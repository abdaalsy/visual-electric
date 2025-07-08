cmake_minimum_required(VERSION 4.1)
project(VisualElectric VERSION 1.0 LANGUAGE CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
set(SOURCES
    main.cpp 
    src/velectric.cpp 
    src/parse.cpp
    src/velectric.cu
)
add_executable(VisualElectric ${SOURCES})

set_target_properties(VisualElectric PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
    CUDA_STANDARD 17
    CXX_STANDARD 17
)