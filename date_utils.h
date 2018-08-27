//
// Created by naked on 26/08/2018.
//

#ifndef FINANAL_FINDATE_H
#define FINANAL_FINDATE_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

using namespace boost::gregorian;

namespace DateUtils {

    date resolve_tenor(date dt, std::string str) {
        std::string::size_type sz;
        char tenor_unit = str[str.length() - 1];
        int tenor_value = stoi(str, &sz);
        switch (tenor_unit) {
            case 'B': {
                days daysObj(tenor_value);
                return dt + daysObj;
            }
            case 'M': {
                months mthObj(tenor_value);
                return dt + mthObj;
            }
            case 'Y': {
                years yrsObj(tenor_value);
                return dt + yrsObj;
            }
            default:
                throw 69;
        }
    }

    double dcf(date dt1, date dt2) {
        date dt_s{dt1.year(), 1, 1};
        date dt_e{dt2.year(), 12, 31};
        return 1 / double((dt_e - dt_s).days()+1);
    }

    double tau(date dt1, date dt2) {
        date_duration dur = dt1 - dt2;
        return double(dur.days()) * dcf(dt1, dt2);
    }

};

#endif //FINANAL_FINDATE_H
