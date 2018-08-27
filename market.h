//
// Created by naked on 26/08/2018.
//

#ifndef FINANAL_MARKET_H
#define FINANAL_MARKET_H

#include <vector>
#include <map>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

class FxVolSurface{
public:
    string pair;
    double vol_given_expiry_strike(date dt, double k){
        return 0.1;
    }
    double vol_given_expiry_delta(date dt, double d){
        return 0.1;
    }
};


class YieldCurve{};

class FxFwdCurve{
public:
    string pair;
    double fwd_rate(date dt){
        return 95.0;
    }
};

class MarketSnap{
    map<string, double> usd_spot_rates;
    map<string, FxVolSurface> fx_vol_surfaces;
    map<string, YieldCurve> yield_curves;
    map<string, FxFwdCurve> fx_fwd_curves ;
};


#endif //FINANAL_MARKET_H
