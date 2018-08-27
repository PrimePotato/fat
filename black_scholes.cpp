#include "black_scholes.h"
#include <cmath>
#include "erfinv.h"
#include "black_scholes.h"
#include <vector>
#include <algorithm>
#include "utils.h"


using namespace ErrorFunction;

namespace BsModel {

    double price(double f, double k, double v, double t, double r, bool call) {
        if (call) {
            return std::exp(-r * t) * (f * normalCDF(d1(f, k, v, t)) - k * normalCDF(d2(f, k, v, t)));
        } else {
            return std::exp(-r * t) * (k * normalCDF(-d2(f, k, v, t)) - f * normalCDF(-d1(f, k, v, t)));
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
        return (1 / (v * std::sqrt(t))) * (std::log(f / k) + 0.5 * v * v * t);
    }

    double d2(double f, double k, double v, double t) {
        return d1(f, k, v, t) - v * std::sqrt(t);
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

    std::vector<double> d1_vector(std::vector<std::vector<double>> args_vector) {
        std::vector<double> out;
        std::transform(args_vector.begin(), args_vector.end(), std::back_inserter(out), &d1_v);
        return out;
    }

    std::vector<double> d2_vector(std::vector<std::vector<double>> args_vector) {
        std::vector<double> out;
        std::transform(args_vector.begin(), args_vector.end(), std::back_inserter(out), &d2_v);
        return out;
    }

    double d1_v(std::vector<double> args) {
        return d1(args[0], args[1], args[2], args[3]);
    }

    double d2_v(std::vector<double> args) {
        return d2(args[0], args[1], args[2], args[3]);
    }


    double price_v(std::vector<double> args, bool call) {
        return price(args[0], args[1], args[2], args[3], args[4], call);
    }

    std::vector<double> price_vector(std::vector<std::vector<double>> args, std::vector<bool> calls) {
        std::vector<double> out;
        for (int i = 0; i < args.size(); ++i) {
            out.push_back(price_v(args[i], calls[i]));
        }

    }

};



