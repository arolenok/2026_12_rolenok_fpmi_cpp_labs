#include <cmath>
#include <iomanip>
#include <iostream>

int main() {

    //var6
    // f(x) = 1/(1+x)^3
    int k;
    std::cout << "k = ";
    std::cin >> k;
    double eps = pow(10, -k);
    double res = 0.0;
    double step = 1.0;

    int i = 1;
    double x;
    std::cout << "x = ";
    std::cin >> x;
    if (x <= -1 || x >= 1) {
        std::cout << "x must be between 0 and 1" << std::endl;
        return 1;
    }

    while (fabs(step) > eps) {
        res += step;
        step *= -x * (i + 2);
        step /= i;
        ++i;
    }

    std::cout << std::setprecision(k) << std::fixed;
    std::cout << "   res = " << res;
    std::cout << "\norigin = " << 1 / pow((1 + x), 3);
    return 0;
}


