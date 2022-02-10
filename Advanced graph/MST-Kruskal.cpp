#include <iostream>
#include <vector>
#include <algorithm>
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

struct Union_Find {
    vector<int> iParent;
    Union_Find(int n) {
        iParent = vector<int> (n);
        for (int i = 0; i < n; i++) iParent[i] = i;
    }

    int Find(int x) {
        if (iParent[x] == x) {
            return x;
        } else {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }

    void Unite(int x, int y) {
        iParent[Find(x)] = Find(y);
    }
}

vector<edge> MST(int n, vector<edge> edges) {
    Union_Find UF(n);
    sort(edges.begin(), edges.end(), [](const edge &a , const edge & b){
        return a.weight < b.weight;
    });
    vector<edge> res;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        if (UF.Find(u) != UF.Find(v)) {
            UF.Unite(u, v);
            res.push_back(Edges[i]);
        }
    }
    return res;
}

int main() {}