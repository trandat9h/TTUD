#include <iostream>
using namespace std;

int n;
int A[1001];

void printSol() {
    for (int i = 1; i <= n; i++) cout << A[i];
    cout << endl;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        A[k] = i;
        if (k == n) printSol();
        else Try(k + 1);
    }
}

int main() {
    n = 10;     // size of binary string
    Try(1);

    return 0;
}