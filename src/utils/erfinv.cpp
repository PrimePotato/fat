#include <cmath>
#include "erfinv.h"

using namespace std;
namespace  {
    const double aa0 = 0.886226899;
    const double aa1 = -1.645349621;
    const double aa2 = 0.914624893;
    const double aa3 = -0.140543331;
    const double bb0 = 1.0;
    const double bb1 = -2.118377725;
    const double bb2 = 1.442710462;
    const double bb3 = -0.329097515;
    const double bb4 = 0.012229801;
    const double cc0 = -1.970840454;
    const double cc1 = -1.62490649;
    const double cc2 = 3.429567803;
    const double cc3 = 1.641345311;
    const double dd0 = 1.0;
    const double dd1 = 3.543889200;
    const double dd2 = 1.637067800;
    const double sqrtPI = sqrt(M_PI);
}

namespace ErrorFunction {
    double erfinv(double x) {
        double r, y;
        int sign_x;

        if (x < -1 || x > 1) {
            return NAN;
        }
        if (x == 0.0) {
            return 0.0;
        }
        if (x > 0) {
            sign_x = 1;
        } else {
            sign_x = -1;
            x = -x;
        }
        if (x <= 0.7) {
            double x2 = x * x;
            r = x * (((aa3 * x2 + aa2) * x2 + aa1) * x2 + aa0);
            r /= (((bb4 * x2 + bb3) * x2 + bb2) * x2 + bb1) * x2 + bb0;
        } else {
            y = sqrt(-log((1.0 - x) / 2.0));
            r = (((cc3 * y + cc2) * y + cc1) * y + cc0);
            r /= ((dd2 * y + dd1) * y + dd0);
        }
        r = r * sign_x;
        x = x * sign_x;
        r -= (erf(r) - x) / (2 / sqrtPI * exp(-r * r));
        r -= (erf(r) - x) / (2 / sqrtPI * exp(-r * r));
        return r;
    }

}

