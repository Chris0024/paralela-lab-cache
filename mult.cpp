#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX 5000

double A[MAX][MAX];
double x[MAX];
double y[MAX];

int main() {

    // Inicializar
    for (int i = 0; i < MAX; i++) {
        x[i] = i;
        y[i] = 0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i + j;
        }
    }

    // Caso 1: i-j
    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end1 = high_resolution_clock::now();
    cout << "Tiempo (i-j): "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms" << endl;

    // Reset
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    // Caso 2: j-i
    auto start2 = high_resolution_clock::now();

    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end2 = high_resolution_clock::now();
    cout << "Tiempo (j-i): "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms" << endl;

    return 0;
}
