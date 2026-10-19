#include <iostream>
#include <string>

int main() {
    std::string str, result = "";
    int counter = 0;

    std::cout << "enter a string (no spaces, numbers and punctuation allowed): ";
    std::getline(std::cin, str);

    if (str.empty()) {
        std::cout << "result: " << std::endl;
        return 0;
    }

    int len = str.length();

    for (int i = 0; i < len; ++i) {
        counter = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            counter++;
            i++;
        }
        if (counter > 1) {
            result = result + str[i] + std::to_string(counter);
        }
        else {
            result = result + str[i];
        }
    }
    std::cout << "result: " << result << std::endl;
    return 0;
}