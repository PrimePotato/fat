//
// Created by naked on 27/11/2019.
//

#include <string>

#ifndef FINANAL_CURRENCY_H
#define FINANAL_CURRENCY_H

#endif //FINANAL_CURRENCY_H

class Currency{
private:
    std::string code;

public:
    Currency(std::string code): code(code){
    }
};


class CurrencyPair{

    Currency lhs, rhs;

public:
    CurrencyPair(Currency lhs, Currency rhs) : lhs(lhs), rhs(rhs) {
    }
};
