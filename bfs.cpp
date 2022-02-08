#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

void input() {
  cin >> N >> M;
  adj.resize(N + 1);
  visited.assign(N + 1, false);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void dosomething(int n) { cout << n << " "; }

void bfs(int u) {
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    dosomething(v);
    for (int w : adj[v]) {
      if (!visited[w]) {
        q.push(w);
        visited[w] = true;
      }
    }
  }
  return;
}

int main() {
  input();
  bfs(1);
  return 0;
}
