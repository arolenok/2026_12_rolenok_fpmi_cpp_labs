#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstdlib>

int Gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

void TryRead(int& number) {
    if (!(std::cin >> number)) {
        std::cout << "Fail on reading the number" << std::endl;
        std::exit(1);
    }
}

int main() {
    int a, b;
    
    std::cout << "Enter a: ";
    TryRead(a);
    
    std::cout << "Enter b: ";
    TryRead(b);
    
    int gcd1 = Gcd(a, b);
    int gcd2 = std::gcd(a, b);
    if (gcd1 != gcd2) {
        std::cout << "You broke my program :(" << std::endl;
        return 1;
    }
    std::cout << "GCD is: " << gcd1 << std::endl;

    return 0;
}