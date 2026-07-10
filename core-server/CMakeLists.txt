cmake_minimum_required(VERSION 3.15)
project(C2Server VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(asio CONFIG REQUIRED)


add_executable(server_app backend/server.cpp)
target_link_libraries(server_app PRIVATE asio::asio)


add_executable(client_app client_test.cpp)
target_link_libraries(client_app PRIVATE asio::asio)