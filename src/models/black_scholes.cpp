#include "black_scholes.h"
#include <cmath>
#include "../utils/erfinv.h"
#include "black_scholes.h"
#include <vector>
#include <algorithm>
#include "../utils/utils.h"


using namespace ErrorFunction;

namespace BsModel {

    double price(double f, double k, double v, double t, double r, bool call) {
        return price_v(new double[5] {f, k, v, t, r}, call);
    }

    double price_v(double *args, bool call) {
        if (call) {
            return std::exp(-*(args + 4) * *(args + 3)) *
                   (*args * normalCDF(d1_v(args)) - *(args + 1) * normalCDF(d2_v(args)));
        } else {
            return std::exp(-*(args + 4) * *(args + 3)) *
                   (*(args + 1) * normalCDF(-d2_v(args)) - *args  * normalCDF(-d1_v(args)));
        }
    }

    double delta(double f, double k, double v, double t, double r, bool call) {
        if (call) {
            return std::erfc(d1(f, k, v, t));
        } else {
            return std::exp(-r * t) * std::erfc(d1(f, k, v, t)) - 1;
        }
    }

    double vega(double f, double k, double v, double t, double r) {
        return std::exp(-r * t) * erfinv(d1(f, k, v, t)) * f * std::sqrt(t);
    }

    double gamma(double f, double k, double v, double t, double r) {
        return std::exp(-r * t) * erfinv(d1(f, k, v, t)) / (f * v * std::sqrt(t));
    }

    double rho(double f, double k, double v, double t, double r, bool call) {
        return -t * price(f, k, v, t, r, call);
    }

    double theta() {
        return 0;
    }

    double dvega_dvol() {
        return 0;
    }

    double dvega_dspot() {
        return 0;
    }

    double normalCDF(double x) {
        return std::erfc(-x / std::sqrt(2)) / 2;
    }

    double d1(double f, double k, double v, double t) {
        return d1_v(new double[4]{f, k, v, t});
    }

    double d2(double f, double k, double v, double t) {
        return d2_v(new double[4]{f, k, v, t});
    }


    std::vector<double> delta_vector(std::vector<double> f, std::vector<double> k,
                                     std::vector<double> v, std::vector<double> t,
                                     std::vector<double> r, std::vector<bool> call) {
//        std::for_each(f.begin(), f.end(), std::erfc);
//        if (call) {
//            auto dbl = ());
//        } else {
//            auto dbl = 0.;
//        }
        return std::vector<double>();
    }

    std::vector<double> d1_vector(std::vector<double *> args_vector) {
        std::vector<double> out;
        std::transform(args_vector.begin(), args_vector.end(), std::back_inserter(out), &d1_v);
        return out;
    }

    std::vector<double> d2_vector(std::vector<double *> args_vector) {
        std::vector<double> out;
        std::transform(args_vector.begin(), args_vector.end(), std::back_inserter(out), &d2_v);
        return out;
    }

    double d1_v(double *args) {
        return (1 / (*(args + 2) * std::sqrt(*(args + 3)))) *
               (std::log(*args / *(args + 1)) + 0.5 * *(args + 2) * *(args + 2) * *(args + 3));
    }

    double d2_v(double *args) {
        return d1_v(args) - *(args + 2) * std::sqrt(*(args + 3));
    }


    std::vector<double> price_vector(std::vector<double *> args, std::vector<bool> calls) {
        std::vector<double> out;
        for (int i = 0; i < args.size(); ++i) {
            out.push_back(price_v(args[i], calls[i]));
        }
        return out;
    }

};



