#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> Adj[10001];
vector<int> Low(10001), Num(10001, -1);
vector<bool> bConnect (10001, false);
int curnum = 0;
stack<int> iComp;

void SCC(int u) {
    iComp.push(u);
    bConnect[u] = true;
    Low[u] = Num[u] = ++curnum;

    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (Num[v] == -1) {
            SCC(v);
            Low[u] = min(Low[u], Low[v]);
        } else if (bConnect[v]) {
            Low[u] = min(Low[u], Num[v]);
        }
    }

    if (Num[u] == Low[u]) {
        cout << "TPLT: ";
        while(1) {
            int cur = iComp.top();
            iComp.pop();
            bConnect[cur] = false;
            cout << cur << ' ';
            if (cur == u) break;
        }
        cout << '\n';
    }
}

void init() {
    Adj[1] = { 3,2 };
    Adj[2] = { 1,5,3 };
    Adj[3] = { 1,2,5 };
    Adj[4] = { };
    Adj[5] = { 2,3,6,7 };
    Adj[6] = { 5,7,8 };
    Adj[7] = { 5,6,8};
    Adj[8] = { 6,7 };

}

int main() {
    init();

    int n = 8; // số đỉnh
    for (int i = 1; i <= n; i++) {
        if (Num[i] == -1) SCC(i);
    }

    return 0;
}
