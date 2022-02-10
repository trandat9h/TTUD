#include <iostream>
using namespace std;

int n;
int A[1001];
bool bMark[1001];

void printSol() {
    for (int i = 1; i <= n; i++) cout << A[i];
    cout << endl;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!bMark[i]) {    // this element have not checked yet
            A[k] = i;
            bMark[i] = true;
            if (k == n) printSol();
            else Try(k + 1);
            bMark[i] = false;
        }
    }
}

int main() {
    n = 5;      // Element number
    Try(1);

    return 0;
}

/* 
 * or you can use next_permutation in algorithm 
 * but array size must <= 9 to avoid TLE
 */