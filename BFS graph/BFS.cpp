#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
queue<int> Q;

void BFS(int start) {
    cout << start << endl;
    Q.push(start);
    bVisited[start] = true;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if (!bVisited[v]) {
                Q.push(v);
                bVisited[v] = true;
                cout << v << ' ';
            }
        }
        cout << endl;
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
    BFS(1);
}