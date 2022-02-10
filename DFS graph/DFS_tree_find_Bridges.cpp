#include <iostream>
#include <vector>
using namespace std;

const int n = 1001;
vector<int> Adj[n];
vector<int> Low(n), Num(n, -1);
int curnum = 0;
vector<pair<int, int>> iiBridges;

void Find_Bridges(int u, int p) {
    Low[u] = Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (v == p) continue;
        if (Num[v] == -1) {
            Find_Bridges(v, u);
            Low[u] = min(Low[u], Low[v]);
        } else {
            Low[u] = min(Low[u], Num[v]);
        }

        if (Low[v] > Num[u]) iiBridges.push_back(make_pair(u, v));
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
    Find_Bridges(1, -1);

    for (auto item: iiBridges) {
        cout << item.first << ' ' << item.second << '\n';
    }
}