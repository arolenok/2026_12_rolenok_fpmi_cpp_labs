#include <iostream>

void multiplyMatrix(int** matrix1, int** matrix2, int**& resultMatrix, const int m, const int n, const int p);
void inputMatrix(int**& matrix, const int m, const int n);
void destroyMatrix(int** matrix, const int m);
void printMatrix(int** matrix, const int m, const int n);

int main() {
    int m, n, p;

    std::cout << "THE FIRST MATRIX" << std::endl;
    std::cout << "enter the number of rows: ";
    std::cin >> m;
    std::cout << "enter the number of columns: ";
    std::cin >> n;

    int** matrix1;

    inputMatrix(matrix1, m, n);

    std::cout << "THE SECOND MATRIX" << std::endl;
    std::cout << "enter the number of rows is " << n << std::endl;
    std::cout << "enter the number of columns: ";
    std::cin >> p;

    int** matrix2;

    inputMatrix(matrix2, n, p);

    std::cout << "THE RESULT MATRIX" << std::endl;

    int** resultMatrix;

    multiplyMatrix(matrix1, matrix2, resultMatrix, m, n, p);

    printMatrix(resultMatrix, m, p);

    destroyMatrix(matrix1, m);
    destroyMatrix(matrix2, n);
    destroyMatrix(resultMatrix, m);

    return 0;
}

void multiplyMatrix(int** matrix1, int** matrix2, int**& matrix, const int m, const int n, const int p) {
    matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[p];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            matrix[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void inputMatrix(int**& matrix, const int m, const int n) {
    std::cout << "INPUT MATRIX" << std::endl;
    matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << "row number " << i + 1 << std::endl;
        for (int j = 0; j < n; ++j) {
            std::cout << "element " << j + 1 << " : ";
            std::cin >> matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void destroyMatrix(int** matrix, const int m) {
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, const int m, const int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
