cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
set(CMAKE_CXX_FLAGS "-std=c++17 -O0")
project(OpenMeshManage)

set(OpenMeshROOT ./3rd/OpenMesh-11.0.0)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(D_GLIBCXX_USE_CXX11_ABI 0)

include_directories(./include/)
include_directories(${OpenMeshROOT}/src/)

file(GLOB_RECURSE SRC ./src/*.cpp)
list(FILTER SRC EXCLUDE REGEX "main.cpp")

add_executable(${PROJECT_NAME} ./src/main.cpp ${SRC})

target_link_libraries(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/${OpenMeshROOT}/build/Build/lib/libOpenMeshCore.so
  ${CMAKE_CURRENT_SOURCE_DIR}/${OpenMeshROOT}/build/Build/lib/libOpenMeshTools.so)
