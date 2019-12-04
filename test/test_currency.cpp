//
// Created by naked on 27/11/2019.
//

#include <boost/test/unit_test_suite.hpp>
#include <iostream>
#include <boost/test/test_tools.hpp>
#include "../src/containers/currency.h"

using namespace std;

BOOST_AUTO_TEST_CASE(test_currency_init) {
    Currency c("EUR");
    std::cout << c.code << std::endl;
;}

BOOST_AUTO_TEST_CASE(test_currency_pair_init) {
    Currency c1("EUR");
    Currency c2("USD");
    CurrencyPair cp(c1,c2);
    std::cout << cp.foreign() << std::endl;
    std::cout << cp.domestic() << std::endl;
    std::cout << cp.payment() << std::endl;
    std::cout << cp.quote() << std::endl;
;}

