cmake_minimum_required(VERSION 3.10)
project(MyStudy)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE CPP_SRC_LIST ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

foreach(v ${CPP_SRC_LIST})
    string(REGEX REPLACE "${PROJECT_SOURCE_DIR}/" "" target_name ${v})
    # rename '/' and '.' to '_'
    string(REGEX REPLACE "/|\\." "_" target_name ${target_name})
    add_executable(${target_name} ${v})
endforeach()
