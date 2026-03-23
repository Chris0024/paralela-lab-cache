#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX 300

double A[MAX][MAX];
double B[MAX][MAX];
double C[MAX][MAX];

int main() {

    
    int BS = 30;     // block size

    // Ini
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = 4 + i + j;
            B[i][j] = 5 +i - j;
            C[i][j] = 0;
        }
    }

    auto start = high_resolution_clock::now();

   
    for (int ii = 0; ii < MAX; ii += BS) {
        for (int jj = 0; jj < MAX; jj += BS) {
            for (int kk = 0; kk < MAX; kk += BS) {

                for (int i = ii; i < min(ii + BS, MAX); i++) {
                    for (int j = jj; j < min(jj + BS, MAX); j++) {
                        for (int k = kk; k < min(kk + BS, MAX); k++) {
                            C[i][j] = C[i][j] + A[i][k] * B[k][j];
                        }
                    }
                }

            }
        }
    }

    auto end = high_resolution_clock::now();

    cout << "Tiempo bloques (N°=" << MAX << ", BS=" << BS << "): "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}
