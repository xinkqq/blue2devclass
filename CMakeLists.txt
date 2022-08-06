cmake_minimum_required(VERSION 3.23)
project(ble2peer)

set(CMAKE_CXX_STANDARD 17)

find_package(spdlog REQUIRED)
if(NOT spdlog_FOUND)
    message("Can't find 'spdlog' library")
    return()
endif()

add_executable(${PROJECT_NAME} src/main.cpp src/dev_class.h src/scan.cpp src/remote_device.cpp src/remote_device.h src/bit_ops.h src/parse_bitmask.cpp src/xml.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog -lbluetooth)