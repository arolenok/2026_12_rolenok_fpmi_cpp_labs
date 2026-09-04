#include <iostream>

int main() {
    int n,m;
    std::cin >> n >> m;
    int a = n;
    int b = m;
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    int gcd = a + b;
    for (int i = 1; i <= gcd / 2; i++) {
        if (gcd % i == 0) {
            std::cout << i << " ";
        }
    }
    if (gcd > 0) {
        std::cout << gcd << std::endl;
    }
    return 0;
}