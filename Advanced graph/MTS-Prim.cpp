#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int u, v;
    int weight;

    edge(int _u, int _v, int _weight) {
        u = _u;
        v = _v;
        weight = _weight;
    }
}

vector<edge> mst(int n, vector<vector<edge>> Adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > PQ:
    vector<edge> res;
    vector<int> iBest_W(n + 1, 1e9), iBest_A(n + 1, -1);
    iBest_W[1] = 0;
    PQ.push({ iBest_W[1], 1 });
    while (res.size() < n - 1) {
        while (!PQ.empty() && PQ.top().first != iBest_W[PQ.top().second]) PQ.pop();
        if (PQ.empty()) return res;

        int w = PQ.top().first, v = PQ.top().second, u = iBest_A[v];
        for (edge e: Adj[v]) {
            if (iBest_W[e.v] > e.weight) {
                iBest_W[e.v] = e.weight;
                iBest_A[e.v] = e.u;
                PQ.push({ iBest_W[e.v], e.v });
            }
        }
        if (v != 1) res.push_back({ u, v, w });
    }
    return res;
}

int main() {

}