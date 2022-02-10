#include <iostream>
using namespace std;

int n, m;
int A[1001];

void printSol() {
    for (int i = 1; i <= m; i++) cout << A[i];
    cout << endl;
}

void Try(int k) {
    for (int i = A[k - 1] + 1; i <= n - m + k; i++) {
        A[k] = i;
        if (k == m) printSol();
        else Try(k + 1);
    }
}

int main() {
    n = 6, m = 3;       // input here
    Try(1);

    return 0;
}