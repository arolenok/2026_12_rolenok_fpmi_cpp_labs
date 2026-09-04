#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n / 100000 + n % 100000 / 10000 + n % 10000 / 1000 == n % 1000 / 100 + n % 100 / 10 + n % 10) {
        std::cout << "LUCKY";
    } else {
        std::cout << "NOT LUCKY";
    }
    return 0;
}