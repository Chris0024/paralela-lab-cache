#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int MAX = 1000;

    vector<vector<double>> A(MAX, vector<double>(MAX));
    vector<double> x(MAX), y(MAX);

    // Inicializar
    for (int i = 0; i < MAX; i++) {
        x[i] = i;
        y[i] = 0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i + j;
        }
    }

    //  Caso 1:
    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);

    cout << "Tiempo (i-j): " << duration1.count() << " ms" << endl;

    // Reset y
    fill(y.begin(), y.end(), 0);

   //  Caso 2:
    auto start2 = high_resolution_clock::now();

    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);

    cout << "Tiempo (j-i): " << duration2.count() << " ms" << endl;

    return 0;
}
