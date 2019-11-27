#include "../src/models/black_scholes.h"
#include <boost/test/included/unit_test.hpp>

using namespace BsModel;

BOOST_AUTO_TEST_CASE(test_price) {
    double a = price(1, 2, 3, 4, 5, true);
    std::cout << a << std::endl;
    BOOST_CHECK(a > 0);
}


BOOST_AUTO_TEST_CASE(test_delta) {
    double a = delta(1, 2, 3, 4, 5, true);
    std::cout << a << std::endl;
    BOOST_CHECK(a > 0);
}


BOOST_AUTO_TEST_CASE(test_vega) {
    double a = vega(1., 1., 0.1, 1., 0.05);
    std::cout << a << std::endl;
    BOOST_CHECK(a > 0);
}


BOOST_AUTO_TEST_CASE(test_gamma) {
    double a = gamma(1., 1., 0.1, 1, 0.05);
    std::cout << a << std::endl;
    BOOST_CHECK(a > 0);
}

