#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Adj[1001];
vector<int> iDist (1001, -1);
queue<int> Q;

void findPath(int start) {
    Q.push(start);
    iDist[start] = 0;

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if (iDist[v] == -1) {
                Q.push(v);
                iDist[v] = 1 + iDist[u];
            }
        }
    }
}

void init() {
    Adj[1] = { 2, 3 };
    Adj[2] = { 5 };
    Adj[3] = { 2, 4 };
    Adj[4] = { 1 };
    Adj[5] = { 6 };
    Adj[6] = { 3, 4, 7, 8, 9 };
    Adj[7] = { 8, 9 };
    Adj[8] = { 11 };
    Adj[9] = { 10 };
    Adj[10] = { 9 };
    Adj[11] = {  };
}

int main() {
    init();
    findPath(1);
    cout << iDist[11];
}