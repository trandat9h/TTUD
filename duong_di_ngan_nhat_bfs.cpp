#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist(1001,-1);
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
    for (int w : adj[v]) {
      if (!visited[w]) {
        q.push(w);
        visited[w] = true;
        dist[w]= dist[v]+1;

      }
    }
  }
  return;
}

int main() {
  input();
  dist[1]=0; // sua dinh xuat phat neu can thiet
  bfs(1);// dinh xuat phat cua bfs
  for(int i=1; i<=N;i++)
  {
      cout<<dist[i]<<" ";
  }
  return 0;
}
//input: dong dau nhap so dinh N va so canh M
//		M dong tiep theo nhap cac canh
		
