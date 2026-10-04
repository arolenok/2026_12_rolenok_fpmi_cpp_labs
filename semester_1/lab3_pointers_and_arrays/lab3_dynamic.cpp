// VARIANT 9

// solve task with usage of
// dynamic arrays

#include <iostream>
#include <cstdlib>
#include <random>

void inputManual(int*, int);
void inputChoice(int&);
void inputRandom(int*, int);
void inputCheck(auto&);
void printArray(int*, int);
bool isNegative(int);
void transformArray(int*, int);


int main() {

    int size, choice;

    std::cout << "enter size: ";
    inputCheck(size);

    if (size <= 0) {
        std::cout << "wrong input. make sure you entered the correct value";
        std::exit(3);
    }

    inputChoice(choice);

    int* array = new int[size];

    if (choice) {
        inputRandom(array, size);
    } else {
        inputManual(array, size);
    }

    std::cout << std::endl << "your array: " << std::endl;
    printArray(array, size);

    std::cout << "transforming array..." << std::endl;
    transformArray(array, size);

    std::cout << "transformed array: " << std::endl;
    printArray(array, size);

    delete[] array;
    return 0;
}



void inputManual(int* arr, int size) {
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

void inputRandom(int* arr, int size) {

    int a, b;

    std::cout << "enter the left border of the interval: ";
    inputCheck(a);

    std::cout << "enter the right border of the interval: ";
    inputCheck(b);

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b);

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

bool isNegative(int number) {
    return number < 0;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void transformArray(int* arr, int size) {
    int* result = new int[size];

    int pos = 0;

    for (int i = 0; i < size; i++) {
        if (isNegative(arr[i])) {
            result[pos++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (!isNegative(arr[i])) {
            result[pos++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = result[i];
    }
    delete[] result;
}