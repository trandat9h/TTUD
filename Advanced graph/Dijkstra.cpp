#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000000

struct edge {
    int u, v;
    int weight;

    edge(int _u, int _v, int _weight) {
        u = _u;
        v = _v;
        weight = _weight;
    }
}

vector<edge> Adj[100];
vector<int> iDist(100, INF);

void Dijkstra(int start) {
    iDist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > PQ;
    PQ.push(make_pair(iDist[start], start));
    while (!PQ.empty()) {
        
    }
}