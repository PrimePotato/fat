//
// Created by naked on 27/08/2018.
//

#ifndef FINANAL_UTILS_H
#define FINANAL_UTILS_H

#include <vector>

namespace utils {

    template<typename T>
    std::vector <T> slice(std::vector <T> &v, int m, int n) {
        std::vector <T> vec;
        std::copy(v.begin() + m, v.begin() + n + 1, std::back_inserter(vec));
        return vec;
    }

}
#endif //FINANAL_UTILS_H
