#include <iostream>
#include <vector>
using namespace std;

vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<bool> bMarked(1001, false);

void DFS(int u) {
    if (bMarked[u]) return;
    bMarked[u] = true; bVisited[u] = true;

    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        bVisited[v] = true;
        DFS(v);
    }
}

void init() {
    Adj[1] = { 2, 3 };
    Adj[2] = { 5 };
    Adj[3] = { 4 };
    Adj[4] = { 1 };
    Adj[5] = { 6 };
    Adj[6] = { 3, 4, 7, 8, 9 };
    Adj[7] = { 8, 9 };
    Adj[8] = { 11 };
    Adj[9] = { 10 };
    Adj[10] = { 9 };
    Adj[11] = { };
}

int main() {
    init();
    DFS(1);

    return 0;
}