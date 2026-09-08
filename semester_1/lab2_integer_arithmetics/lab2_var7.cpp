#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    for (int a = 1; a <= n; ++a ) {
        for (int b = a; b <= n; ++b ) {
            int c = std::lround(std::sqrt(a*a + b*b));
            if (a*a + b*b == c*c && c <= n) {
                std::cout << a << " " << b << " " << c << std::endl;
            }
        }
    }
    return 0;
}