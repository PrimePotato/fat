

/* The following is a simple example that shows conversion of dates
 * to and from a std::string.
 *
 * Expected output:
 * 2001-Oct-09
 * 2001-10-09
 * Tuesday October 9, 2001
 * An expected exception is next:
 * Exception: Month number is out of range 1..12
 */

#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <string>
#include "trade.h"
#include "date_utils.h"
#include <vector>
#include "market.h"
#include <random>
#include "black_scholes.h"

int main() {

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(90, 110);

    using namespace boost::gregorian;
    using namespace DateUtils;
    using namespace std;
    using namespace BsModel;

    string s = "2018-10-9";
    date d(from_simple_string(s));

    date dateObj1{2015, 3, 21};
    date dateObj2{2015, 10, 1};
    date_duration dur = dateObj2 - dateObj1;


    int n = 3;
    vector<Option> trades;
    for (int i = 0; i < n; ++i) {
        Option opt = {(double) distribution(generator), resolve_tenor(d, "10B")};
        trades.push_back(opt);
    };

    std::cout << trades[0].expiry << std::endl;

    std::cout << resolve_tenor(dateObj1, "10B") << std::endl;
    std::cout << resolve_tenor(dateObj1, "10M") << std::endl;
    std::cout << resolve_tenor(dateObj1, "10Y") << std::endl;

    std::cout << delta(1, 2, 3, 4, 5, true) << std::endl;

//    std::cout << BsModel::d1_v({1, 2, 3, 4}) << std::endl;
//    std::cout << BsModel::d1_v({1, 2, 3, 4}) << std::endl;
    std::cout << BsModel::d1_v({1, 2, 3, 4}) << std::endl;
    auto bsm1 = BsModel::d1_vector({{1, 2, 3, 4},{ 3, 4, 5, 6}}) ;
    auto bsm2 = BsModel::d2_vector({{1, 2, 3, 4},{ 3, 4, 5, 6}}) ;

    auto prc = BsModel::price_vector({{1, 2, 3, 4,5},{ 3, 4, 5, 6,7}},{true,true});
//    std::cout << BsModel::d1_vector({{1, 2, 3, 4},{3, 4, 5, 6}}) << std::endl;


    std::cout << tau(dateObj1, dateObj2) << std::endl;

    FxVolSurface fvs = {"USDJPY"};
    std::cout << fvs.vol_given_expiry_delta(dateObj1, 0.1) << std::endl;

    return 0;
}
