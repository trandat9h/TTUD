#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<vector<int>> distances;
int V, E, start_v;

set<int> shortest_path_tree;
vector<int> d;

bool operator<(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

void input() {
  cin >> V >> E;
  cin >> start_v;
  adj_list.resize(V);
  distances.resize(V);
  for (int i = 0; i < V; i++) {
    distances[i].assign(V, INT_MAX);
  }
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
    distances[a][b] = c;
    distances[b][a] = c;
  }
}

void init_data() {
  shortest_path_tree.clear();
  d.assign(V, INT_MAX);
  d[start_v] = 0;
}

void dijkstra(int v) {
  // do something
  priority_queue<pair<int, int>> min_heap;
  min_heap.push({v, 0});
  while (min_heap.size() > 0) {
    auto curr = min_heap.top();
    min_heap.pop();
    int u = curr.first;
    int dist_vu = curr.second;
    shortest_path_tree.insert(u);
    for (int i = 0; i < adj_list[u].size(); i++) {
      int w = adj_list[u][i];
      if (distances[u][w] + dist_vu < d[w]) {
        d[w] = distances[u][w] + dist_vu;
        min_heap.push({w, d[w]});
      }
    }
  }
  return;
}

int main() {
  input();
  init_data();
  dijkstra(start_v);
  for (int i = 0; i < d.size(); i++) {
    cout << d[i] << " ";
  }
  return 0;
}
