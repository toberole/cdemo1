cmake_minimum_required(VERSION 3.8)
project("cdemo1")

add_definitions(-std=c++17)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/include SRC_DIR)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_DIR)

add_executable(main ${SRC_DIR})