//
// Created by naked on 25/08/2018.
//

#ifndef FINANALYTICS_OPTION_H
#define FINANALYTICS_OPTION_H

#include <chrono>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <vector>

using namespace boost::gregorian;

class Trade {
};


class Option: public Trade {
public:
    double strike;
    date expiry;
    Option(double k, date dt);
};

class Portfolio{
public:
    std::vector<Trade> trades;
};

#endif //FINANALYTICS_OPTION_H
