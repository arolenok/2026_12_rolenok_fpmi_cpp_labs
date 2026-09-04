#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n % 10 == n / 1000 && n % 100 / 10 == n % 1000 / 100) {
        std::cout << "PALINDROME" << std::endl;
    } else {
        std::cout << "NOT PALINDROME" << std::endl;
    }
}