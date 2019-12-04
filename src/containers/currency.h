//
// Created by naked on 27/11/2019.
//

#include <string>
#include <cstring>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <map>
#include <yaml.h>


#ifndef FINANAL_CURRENCY_H
#define FINANAL_CURRENCY_H

#endif //FINANAL_CURRENCY_H

#include <iostream>


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using namespace std;

class Currency {
public:
    static  map<string, int> quote_map;
    static  map<string, int> payment_map;

    char code[3];
    int payment_rank;

    int quote_rank;

    Currency(std::string name) {
        std::strcpy(code, name.c_str());
        payment_rank = payment_map[name];
        quote_rank = quote_map[name];
    }

    friend ostream &operator<<(ostream &out, const Currency &c);

};


ostream &operator<<(ostream &out, const Currency &c) {
    out << c.code;
    return out;
}


//map<string, int> Currency::quote_map = get_quote_map();
map<string, int> Currency::quote_map = {
    {"EUR", 1},
    {"GBP", 2},
    {"AUD", 3},
    {"NZD", 4},
    {"USD", 5},
    {"JPY", 6},
};

map<string, int> Currency::payment_map = {
        {"USD", 1},
        {"EUR", 2},
        {"GBP", 3},
        {"AUD", 4},
        {"NZD", 5},
        {"JPY", 6},
};

class CurrencyPair {
private:
    Currency lhs, rhs;

public:
    CurrencyPair(Currency lhs, Currency rhs) : lhs(lhs), rhs(rhs) {
    }

    Currency foreign() {
        return lhs;
    }

    Currency domestic() {
        return rhs;
    }

    Currency quote() {
        return (lhs.quote_rank>rhs.quote_rank) ? lhs : rhs;
    }

    Currency payment() {
        return (lhs.payment_rank>rhs.payment_rank) ? lhs : rhs;
    }

};
