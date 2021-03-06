//
// Created by naked on 26/08/2018.
//

#ifndef FINANAL_RISK_ENGINE_H
#define FINANAL_RISK_ENGINE_H

#include "market.h"
#include "trade.h"
#include "../models/model_config.h"
#include <vector>

class RiskEngine{
public:
    MarketSnap mkt_snap;
    Portfolio prt;
    ModelConfig mlc;
    std::vector<double> get_valuation();
};


#endif //FINANAL_RISK_ENGINE_H
