#include <cstdlib>
#include <iostream>

void TryRead(int& number) {
    if (!(std::cin >> number)) {
        std::cout << "Fail on reading the number." << std::endl;
        std::exit(1);
    }
}

bool IsPositive(int number) {
    return number > 0;
}

int main() {
    int number;

    std::cout << "Enter the number: ";
    TryRead(number);

    if (IsPositive(number)) {
        std::cout << "The number is positive." << std::endl;
    } else {
        std::cout << "The number is not positive." << std::endl;
    }

    return 0;
}