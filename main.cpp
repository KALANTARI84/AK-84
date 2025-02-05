#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int maxCol = 10;

void inputMatrix(int matrix[][maxCol], int row, int col) {
    cout << "Enter elements of the matrix (" << row << "x" << col << "):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][maxCol], int row, int col) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sortMatrix(int matrix[][maxCol], int row, int col) {

    int size = row * col;
    int temp[size];
    int index = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp[index++] = matrix[i][j];
        }
    }

    sort(temp, temp + size);

    index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = temp[index++];
        }
    }
}

void searchMatrix(const int matrix[][maxCol], int row, int col, int target) {
    bool found = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == target) {
                cout << "Element " << target << " found at position [" << i << "][" << j << "]." << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Element " << target << " not found in the matrix." << endl;
    }
}

void multiply(const int A[][maxCol], const int B[][maxCol], int m, int p, int n, int C[][maxCol]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void addMatrix(const int A[][maxCol], const int B[][maxCol], int row, int col, int C[][maxCol]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(const int A[][maxCol], const int B[][maxCol], int row, int col, int C[][maxCol]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void scalarMultiply(int matrix[][maxCol], int row, int col, int scalar) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

void editElement(int matrix[][maxCol], int row, int col, int i, int j, int newValue) {
    if (i >= 0 && i < row && j >= 0 && j < col) {
        matrix[i][j] = newValue;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void sumRows(const int matrix[][maxCol], int row, int col) {
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
    }
}

void sumColumns(const int matrix[][maxCol], int row, int col) {
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j << ": " << sum << endl;
    }
}

int sumMainDiagonal(const int matrix[][maxCol], int row, int col) {
    int sum = 0;
    for (int i = 0; i < row && i < col; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int countZeros(const int matrix[][maxCol], int row, int col) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void checkMatrixType(const int matrix[][maxCol], int row, int col) {
    bool isUpperTriangular = true;
    bool isLowerTriangular = true;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i > j && matrix[i][j] != 0) {
                isLowerTriangular = false;
            }
            if (i < j && matrix[i][j] != 0) {
                isUpperTriangular = false;
            }
        }
    }

    if (isUpperTriangular) {
        cout << "The matrix is upper triangular." << endl;
    } else if (isLowerTriangular) {
        cout << "The matrix is lower triangular." << endl;
    } else {
        cout << "The matrix is neither upper nor lower triangular." << endl;
    }
}

int main() {
    int m1, p1, m2, p2;

    cout << "Enter the number of rows for matrix1: ";
    cin >> m1;
    cout << "Enter the number of columns for matrix1: ";
    cin >> p1;

    cout << "Enter the number of rows for matrix2: ";
    cin >> m2;
    cout << "Enter the number of columns for matrix2: ";
    cin >> p2;

    int matrix1[maxCol][maxCol], matrix2[maxCol][maxCol], result[maxCol][maxCol];

    inputMatrix(matrix1, m1, p1);

    inputMatrix(matrix2, m2, p2);

    cout << "\nmatrix1 is :\n";
    printMatrix(matrix1, m1, p1);

    cout << "\nmatrix2 is :\n";
    printMatrix(matrix2, m2, p2);

    sortMatrix(matrix1, m1, p1);
    cout << "\nmatrix1 after sorting:\n";
    printMatrix(matrix1, m1, p1);

    int target;
    cout << "\nEnter an element to search in matrix1: ";
    cin >> target;
    searchMatrix(matrix1, m1, p1, target);

    if (p1 == m2) {
        multiply(matrix1, matrix2, m1, p1, p2, result);
        cout << "\nMultiply of matrix1 and matrix2 is :\n";
        printMatrix(result, m1, p2);
    } else {
        cout << "\nMatrix multiplication is not possible (columns of matrix1 != rows of matrix2)." << endl;
    }

    if (m1 == m2 && p1 == p2) {
        addMatrix(matrix1, matrix2, m1, p1, result);
        cout << "\nSum of matrix1 and matrix2 is :\n";
        printMatrix(result, m1, p1);
    } else {
        cout << "\nMatrix addition is not possible (dimensions do not match)." << endl;
    }

    if (m1 == m2 && p1 == p2) {
        subtractMatrix(matrix1, matrix2, m1, p1, result);
        cout << "\nSubtraction of matrix1 and matrix2 is :\n";
        printMatrix(result, m1, p1);
    } else {
        cout << "\nMatrix subtraction is not possible (dimensions do not match)." << endl;
    }

    int scalar;
    cout << "\nEnter a scalar to multiply with matrix1: ";
    cin >> scalar;
    scalarMultiply(matrix1, m1, p1, scalar);
    cout << "Matrix1 after scalar multiplication:\n";
    printMatrix(matrix1, m1, p1);

    int i, j, newValue;
    cout << "\nEnter the row and column index to edit in matrix1: ";
    cin >> i >> j;
    cout << "Enter the new value: ";
    cin >> newValue;
    editElement(matrix1, m1, p1, i, j, newValue);
    cout << "Matrix1 after editing:\n";
    printMatrix(matrix1, m1, p1);

    cout << "\nSum of rows in matrix1:\n";
    sumRows(matrix1, m1, p1);

    cout << "\nSum of columns in matrix1:\n";
    sumColumns(matrix1, m1, p1);

    if (m1 == p1) {
        cout << "\nSum of main diagonal in matrix1: " << sumMainDiagonal(matrix1, m1, p1) << endl;
    } else {
        cout << "\nMatrix1 is not square, cannot compute main diagonal sum." << endl;
    }

    cout << "\nNumber of zeros in matrix1: " << countZeros(matrix1, m1, p1) << endl;

    if (m1 == p1) {
        checkMatrixType(matrix1, m1, p1);
    } else {
        cout << "\nMatrix1 is not square, cannot determine if it is triangular." << endl;
    }

    return 0;
}
