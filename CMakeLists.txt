cmake_minimum_required(VERSION 3.8)

project("cdemo1")

message("${MSVC_VERSION}")

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_COMPILER  "/usr/bin/g++-7")
set(CMAKE_CXX_FLAGS "-std=c++1z")

#if (MSVC_VERSION GREATER_EQUAL "1900")
#    include(CheckCXXCompilerFlag)
#    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
#    if (_cpp_latest_flag_supported)
#        add_compile_options("/std:c++latest")
#    endif()
#endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/include SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/include/demo2 SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/include/demo3 SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/include/fake_sp SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/util SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/demo1 SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/demo2 SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/demo3 SRC_DIR)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_DIR)

add_executable(main ${SRC_DIR})