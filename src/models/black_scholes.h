//
// Created by naked on 25/08/2018.
//

#ifndef FINANALYTICS_BLACK_SCHOLES_H
#define FINANALYTICS_BLACK_SCHOLES_H

#include <vector>
#include <array>


namespace BsModel {

    double price(double f, double k, double v, double t, double r, bool call);

    double price_v(double* args, bool call);

    std::vector<double> price_vector(std::vector<double*> args, std::vector<bool> calls);

    double delta(double f, double k, double v, double t, double r, bool call);

    std::vector<double> delta_vector(
            std::vector<double> f,
            std::vector<double> k,
            std::vector<double> v,
            std::vector<double> t,
            std::vector<double> r,
            std::vector<bool> call
    );

    double normalCDF(double x);

    double d1(double f, double k, double v, double t);

    double d1_v(double* args);

    double d2_v(double args[4]);

    std::vector<double> d1_vector(std::vector<double*> args);

    std::vector<double> d2_vector(std::vector<double*> args);

    double d2(double f, double k, double v, double t);

    double vega(double f, double k, double v, double t, double r);

    double gamma(double f, double k, double v, double t, double r);

    double rho(double f, double k, double v, double t, double r);

    double theta(double f, double k, double v, double t, double r);

    double dvega_dvol(double f, double k, double v, double t, double r);

    double dvega_dspot(double f, double k, double v, double t, double r);
};

#endif //FINANALYTICS_BLACK_SCHOLES_H
