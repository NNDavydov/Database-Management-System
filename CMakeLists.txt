cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(homework_1)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/basic_faculties.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>")

target_link_libraries(demo ${PROJECT_NAME})
