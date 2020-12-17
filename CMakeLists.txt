cmake_minimum_required(VERSION 3.12)
project(FinAnal)

set(CMAKE_CXX_STANDARD 17)
set(INCLUDE_TEST true)

file(GLOB SOURCES "src/*.h")
file(GLOB SOURCES "src/*.cpp")
file(GLOB SOURCES "test/*.cpp")
file(GLOB TEST_SOURCES "test/*.cpp")

if (INCLUDE_TEST)
    add_executable(FinAnal ${SOURCES} ${TEST_SOURCES})
else()
    add_executable(FinAnal ${SOURCES})
endif()

find_package(Boost 1.36.0 COMPONENTS date_time)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(FinAnal ${Boost_LIBRARIES})
endif ()


