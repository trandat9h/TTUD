#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<bool> visited;
vector<vector<int>> adj;

void operate(int N) { cout << N << " "; }

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

void dfs(int v) {
  operate(v);
  visited[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    if (!visited[adj[v][i]]) {
      dfs(adj[v][i]);
    }
  }
}

int main() {
  input();
  dfs(1);
  return 0;
}
