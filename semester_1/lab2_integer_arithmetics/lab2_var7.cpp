#include <iostream>
#include <cmath>

int main() {
    long long n;
    long long squares_sum, c;
    bool flag = false;
    std:: cout << "enter a positive integer: ";
    if (std::cin >> n and n > 0) {
        std::cout << "pythagorean triples for n = " << n << ":" << std::endl;
        for (long long a = 1; a <= n; a++) {
            if (a * a + a * a > n * n) break;
            for (long long b = a; b <= n; b++) {
                squares_sum = a * a + b * b;
                if (squares_sum > n * n) break;
                c = (long long)std::sqrt((double) squares_sum);
                if (c <= n and c * c == squares_sum) {
                    std::cout << "a = " << a << ", " << "b = " << b << ", " << "c = " << c << std::endl;
                    flag = true;
                    }
                }
            }
        if (!flag) {
            std::cout << "no pythagorean triples found." << std::endl;
        }
        return 0;
    } else {
        std::cout << "invalid input. try again. possible errors: negative numbers, zero, or non-integer values." << std::endl;
        return 1;
    }
}