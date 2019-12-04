//
// Created by naked on 27/08/2018.
//

#ifndef FINANAL_UTILS_H
#define FINANAL_UTILS_H

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>


namespace utils {

    template<typename T>
    std::vector<T> slice(std::vector<T> &v, int m, int n) {
        std::vector<T> vec;
        std::copy(v.begin() + m, v.begin() + n + 1, std::back_inserter(vec));
        return vec;
    }

//    double lerp123(double a, double b, double f) {
//        return a + f * (b - a);
//    }
    
//    bool compare(const std::pair<double, double> &i, const std::pair<double, double> &j) {
//        return i.first < j.first;
//    }
//
//    double interpolate(std::vector<std::pair<double, double>> pts, double x) {
//        sort(pts.begin(), pts.end(), compare);
//        auto it = pts.begin();
//        std::vector<std::pair<double, double>>::iterator prev;
//        while (x > it->first) {
//            prev = it++;
//        }
//        double d0 = prev->first - x / (prev->first - it->first);
//        return 0.1;
//    }

}
#endif //FINANAL_UTILS_H
