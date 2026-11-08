cmake_minimum_required(VERSION 3.20)
project(fpmi_gcd_lab)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/*.cpp)
list(FILTER SOURCES EXCLUDE REGEX "/(cmake-build[^/]*|build|\\.git|\\.idea)/")

foreach(src ${SOURCES})
    file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${src})
    string(REGEX REPLACE "\\.cpp$" "" name ${rel})
    string(REPLACE "/" "_" name ${name})
    add_executable(${name} ${src})

    get_filename_component(dir ${src} DIRECTORY)
    set_target_properties(${name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${dir})
endforeach()
