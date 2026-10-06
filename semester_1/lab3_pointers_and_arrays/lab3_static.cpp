// VARIANT 7

// solve task with usage of
// static arrays

#include <iostream>
#include <cstdlib>
#include <random>

void inputManual(double*, int);
void inputChoice(int&);
void inputRandom(double*, int);
void inputCheck(auto&);
void printArray(double*, int);
bool isSuitable(double);
void transformArray(double*, int);
int countSuitable(double*, int);
bool canTransform(double*, int);

const int MAX_LENGTH = 100;

int main() {

    int size, choice;
    double array[MAX_LENGTH];

    std::cout << "enter size (no more than " << MAX_LENGTH << "): ";
    inputCheck(size);

    if (size > MAX_LENGTH || size <= 0) {
        std::cout << "wrong input. make sure you entered the correct value";
        std::exit(3);
    }

    inputChoice(choice);

    if (choice) {
        inputRandom(array, size);
    } else {
        inputManual(array, size);
    }

    std::cout << std::endl << "your array: " << std::endl;
    printArray(array, size);
    if (!canTransform(array, size)) {
        std::cout << "transformation is impossible" << std::endl;
        return 0;
    }
    std::cout << "transforming array..." << std::endl;
    transformArray(array, size);
    std::cout << "transformed array: " << std::endl;
    printArray(array, size);

    return 0;
}


void inputManual(double* arr, int size) {
    std::cout << "enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        inputCheck(arr[i]);
    }
}

void inputChoice(int& choice_i) {

    std::cout << "type 0 for manual input, type 1 for random input: ";

    inputCheck(choice_i);

    if (choice_i != 0 && choice_i != 1) {
        std::cout << "wrong input. make sure you entered the correct value";
        std::exit(2);
    }
}

void inputRandom(double* arr, int size) {

    double a, b;

    std::cout << "enter the left border of the interval: ";
    inputCheck(a);

    std::cout << "enter the right border of the interval: ";
    inputCheck(b);

    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(a, b);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }

}

void inputCheck(auto &neededInput) {
    if (!(std::cin >> neededInput)) {
        std::cout << "wrong input. make sure you entered the correct value";
        std::exit(1);
    }
}

bool isSuitable(double number) {
    int integerPart = static_cast<int>(number);
    return 0 <= integerPart && integerPart <= 10;
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void transformArray(double* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isSuitable(arr[i])) {
            double tmp = arr[i];
            for (int j = i; j > count; j--) {
                arr[j] = arr[j - 1];
            }
            arr[count] = tmp;
            count++;
        }
    }
    for (int k = count - 1; k >= 1; k--) {
        double tmp = arr[k];
        for (int j = k; j < 2 * k; j++) {
            arr[j] = arr[j + 1];
        }
        arr[2 * k] = tmp;
    }
}


int countSuitable(double* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isSuitable(arr[i])) {
            count++;
        }
    }
    return count;
}

bool canTransform(double* arr, int size) {
    int suitableCount = countSuitable(arr, size);
    int evenSlots = (size + 1) / 2;
    return suitableCount <= evenSlots;
}