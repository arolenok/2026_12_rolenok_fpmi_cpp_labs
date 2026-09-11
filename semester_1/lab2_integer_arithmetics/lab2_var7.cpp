#include <iostream>
#include <cmath>

int main() {
    int n, c, squares_sum;
    bool flag = false;
    std:: cout << "enter an integer: ";
    if (std::cin >> n and n > 0) {
        std::cout << "pythagorean triples for n = " << n << ":" << std::endl;
        for (int a = 1; a<= n; a++) {
            for (int b = a; b <= n; b++) {
                squares_sum = a * a + b * b;
                c = std::sqrt(squares_sum);
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