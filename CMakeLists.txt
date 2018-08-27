cmake_minimum_required(VERSION 3.12)
project(FinAnal)

find_package(Boost 1.36.0 COMPONENTS date_time)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_executable(FinAnal main.cpp date_utils.h market.h risk_engine.h trade.cpp erfinv.h erfinv.cpp black_scholes.cpp black_scholes.h utils.h)
    target_link_libraries(FinAnal ${Boost_LIBRARIES})
endif ()


set(CMAKE_CXX_STANDARD 17)

#add_executable(FinAnal main.cpp)