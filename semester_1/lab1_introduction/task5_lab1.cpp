#include <iostream>

int main () {
    int m = -1, k = 1, n, temp = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        temp = k;
        k = k + m;
        m = temp;
        std::cout << k << " ";
    }
    return 0;
}