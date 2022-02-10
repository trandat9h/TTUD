#include <iostream>
#include <vector>
using namespace std;

vector<int> Adj[1001];
vector<int> iComponent(1001, -1);

void findComponent(int curComp, int u) {
    if (iComponent[u] != -1) return;

    iComponent[u] = curComp;
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        findComponent(curComp, v);
    }
}

void init() {
    Adj[1] = { 2, 3 };
    Adj[2] = { 1, 3 };
    Adj[3] = { 1, 2, 4 };
    Adj[4] = { 3, 6, 9 };
    Adj[5] = { 6, 8, 11 };
    Adj[6] = { 4, 5, 7, 9 };
    Adj[7] = { 6, 9, 10 };
    Adj[8] = { 5, 11 };
    Adj[9] = { 4, 6, 7 };
    Adj[10] = { 7 };
    Adj[11] = { 5, 8 };
}

int main() {
    init();

    int numComp = 0;
    for (int u = 1; u <= 11; u++) {
        if (iComponent[u] == -1) {
            findComponent(numComp, u);
            numComp++;
        }
    }
    cout << numComp;

    // for (int u = 1; u <= 11; u++) {
    //     cout << iComponent[u] << ' ';
    // }
}