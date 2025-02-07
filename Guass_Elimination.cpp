//Gaussian Elimination Implimentation.
#include <iostream>
#include <cmath>

using namespace std;

void Gauss_E(double** A, double* solution, int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        if (maxRow != i) {
            for (int j = 0; j <= n; j++) {
                swap(A[i][j], A[maxRow][j]);
            }
        }

        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) {
                A[k][j] -= A[i][j] * factor;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        solution[i] = A[i][n] /A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            A[k][n] -= A[k][i] * solution[i];
        }
    }
}
void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of variables (size of the matrix): ";
    cin >> n;


    double** Ar= new double*[n];
    for (int i = 0; i < n; i++) {
        Ar[i] = new double[n + 1];
    }

    double* solution = new double[n];


    cout << "Enter the matrix (coefficients + constants):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> Ar[i][j];
        }
    }
    Gauss_E(Ar, solution, n);

    cout << "\nThe solution is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] Ar[i];
    }
    delete[] Ar;
    delete[] solution;

    return 0;
}

