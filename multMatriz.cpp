#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX 3000

double A[MAX][MAX];
double B[MAX][MAX];
double C[MAX][MAX];

int main() {
    // Ini
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = 2+i+j;
            B[i][j] = 3+j-i;
            C[i][j] = 0;
        }
    }

    auto start = high_resolution_clock::now();

  
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = high_resolution_clock::now();

    cout << "Tiempo (N° de elementos =" << MAX << "): " << duration_cast<milliseconds>(end - start).count()<< " ms" << endl;

    return 0;
}
