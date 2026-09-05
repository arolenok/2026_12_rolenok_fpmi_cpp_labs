#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << std::string(3*(n-1), ' ');
    int symbol_counter = 3*(n-1);
    for (int i = 1; i <= k; i++) {
        if (i <= 9) {
            std::cout << ' ' << i;
            symbol_counter += 2;
            if (symbol_counter < 20 && i!=k) {
                std::cout << ' ';
                symbol_counter++;
            }
        } else {
            std::cout << i;
            symbol_counter += 2;
            if (symbol_counter < 20 && i!=k) {
                std::cout << ' ';
                symbol_counter++;
            }
        }
        if (symbol_counter == 20) {
            std::cout << '\n';
            symbol_counter = 0;
        }
    }
    if (symbol_counter != 0) {
        std::cout << '\n';
    }
    return 0;
}