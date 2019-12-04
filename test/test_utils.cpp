//
// Created by naked on 27/11/2019.
//


#include <boost/test/unit_test_suite.hpp>
#include <iostream>
#include <boost/test/test_tools.hpp>
#include "../src/utils/utils.h"
//#include "../src/utils/utils.h"

using namespace utils;

BOOST_AUTO_TEST_CASE(test_interpolate) {
    std::vector<std::pair<double, double>> p = {{.1, .2},
                                                {.2, .4},
                                                {.3, .6},
                                                {.4, .8}};
//    double y = utils::interpolate(p, 0.1);

}
