cmake_minimum_required(VERSION 3.23)
project(ci_cd_test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)

add_library(ping STATIC src/ping.cpp)
add_executable(ping_sandbox main.cpp)
add_executable(ping_test ping_test.cpp)

target_include_directories(ping PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_INCLUDE_DIRS})
target_include_directories(ping_sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ping_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_INCLUDE_DIRS})

target_link_libraries(ping_test ping ${CONAN_LIBS})
target_link_libraries(ping_sandbox ${CONAN_LIBS} ping)

enable_testing()

add_test(
    NAME ping_test
    COMMAND $<TARGET_FILE:ping_test> --log_level=error
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
