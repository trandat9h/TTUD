#include <iostream>
#include <vector>
using namespace std;

vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<int> iOrder;

void Topo_sort(int u) {
    if (bVisited[u]) return;

    bVisited[u]= true;
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        Topo_sort(v);
    }
    iOrder.push_back(u);
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
    Topo_sort(1);       // start node

    for (auto item: iOrder) cout << item << ' ';
}