cmake_minimum_required(VERSION 3.5)
project(ATM)

set(CMAKE_BUILD_TYPE Debug)

# for C++11 compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ATM src/main.cpp src/Account.cpp src/Card.cpp src/BankSystem.cpp)

