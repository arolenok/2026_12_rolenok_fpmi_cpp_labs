#include <iostream>
#include <random>
#include <utility>
#include <cstdlib>

void solveMatrix(int** source, int** matrix, const int rows, const int columns);
void inputMatrix(int**& matrix, const int rows, const int columns);
void destroyMatrix(int** matrix, const int rows);
void printMatrix(int** matrix, const int rows, const int columns);
void inputChoice(int&);
void inputRandom(int**& matrix, const int rows, const int columns);
void inputCheck(auto&, int** = nullptr, const int = 0);
void createMatrix(int**& matrix, const int rows, const int columns);

int main() {
    int rows, columns, choice;

    inputChoice(choice);

    std::cout << "enter the number of rows: ";
    inputCheck(rows);
    std::cout << "enter the number of columns: ";
    inputCheck(columns);
    std::cout << std::endl;

    if (rows <= 0 || columns <= 0) {
        std::cout << "wrong input. size must be positive" << std::endl;
        std::exit(3);
    }

    int** matrix = nullptr;

    if (choice == 0) {
        inputMatrix(matrix, rows, columns);
    } else if (choice == 1) {
        inputRandom(matrix, rows, columns);
    }

    std::cout << "YOUR MATRIX" << std::endl;

    printMatrix(matrix, rows, columns);

    std::cout << "THE RESULT MATRIX" << std::endl;

    int** resultMatrix = nullptr;

    createMatrix(resultMatrix, rows, columns);
    solveMatrix(matrix, resultMatrix, rows, columns);

    printMatrix(resultMatrix, rows, columns);

    destroyMatrix(matrix, rows);
    destroyMatrix(resultMatrix, rows);

    return 0;
}

void solveMatrix(int** source, int** matrix, const int rows, const int columns) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            for (int row_i = 0; row_i < rows; ++row_i) {
                matrix[row][col] += source[row_i][col];
            }

            for (int col_i = 0; col_i < columns; ++col_i) {
                matrix[row][col] += source[row][col_i];
            }

            matrix[row][col] -= source[row][col];
        }
    }
}

void inputMatrix(int**& matrix, const int rows, const int columns) {
    std::cout << "INPUT MATRIX" << std::endl;
    createMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; ++i) {
        std::cout << "row number " << i + 1 << std::endl;
        for (int j = 0; j < columns; ++j) {
            std::cout << "element " << j + 1 << " : ";
            inputCheck(matrix[i][j], matrix, rows);
        }
        std::cout << std::endl;
    }
}

void destroyMatrix(int** matrix, const int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, const int rows, const int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inputChoice(int& choice_i) {

    std::cout << "type 0 for manual input, type 1 for random input: ";

    inputCheck(choice_i);

    if (choice_i != 0 && choice_i != 1) {
        std::cout << "wrong input. make sure you entered the correct value" << std::endl;
        std::exit(2);
    }
}

void inputRandom(int**& matrix, const int rows, const int columns) {

    createMatrix(matrix, rows, columns);

    int a, b;

    std::cout << "enter the left border of the interval: ";
    inputCheck(a, matrix, rows);

    std::cout << "enter the right border of the interval: ";
    inputCheck(b, matrix, rows);

    if (a > b) {
        std::swap(a,b);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            matrix[row][col] = dis(gen);
        }
    }

}

void inputCheck(auto &neededInput, int** matrix, const int rows) {
    if (!(std::cin >> neededInput)) {
        std::cout << "wrong input. make sure you entered the correct value" << std::endl;
        if (matrix) destroyMatrix(matrix, rows);
        std::exit(1);
    }
}

void createMatrix(int**& matrix, const int rows, const int columns) {
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            matrix[row][col] = 0;
        }
    }
}

