cmake_minimum_required(VERSION 3.12)
project(FinAnal)

find_package(Boost 1.36.0 COMPONENTS date_time)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
#    add_executable(FinAnal src/*)

    file(GLOB SOURCES "src/*.h")
    file(GLOB SOURCES "src/*.cpp")
    file(GLOB SOURCES "test/*.cpp")
    add_executable(FinAnal ${SOURCES})
#    add_executable(FinAnal src/utils/date_utils.h src/containers/market.h src/containers/calculation_engine.h src/containers/trade.cpp
#            src/utils/erfinv.h src/utils/erfinv.cpp src/models/black_scholes.cpp src/models/black_scholes.h src/utils/utils.h src/models/model_config.cpp
#            src/models/model_config.h src/containers/calculation_engine.cpp test/test_black_scholes.cpp src/main_old.cpp test/test_runner.cpp test/test_date_utils.cpp src/containers/currency.h test/test_currency.cpp src/models/yield_curve.cpp src/models/yield_curve.h test/test_utils.cpp src/static/conventions.h)
    target_link_libraries(FinAnal ${Boost_LIBRARIES})
endif ()


set(CMAKE_CXX_STANDARD 17)

#add_executable(FinAnal main.aglib)