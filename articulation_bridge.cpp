#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/cutpoints.html
// infos on the problem and algorithms available

int N, M;
vector<vector<int>> adjacentList;
vector<bool> visited;
vector<int> entryPoint;
vector<int> lowPoint;
set<int> curVertices;
vector<pair<int, int>> bridges;
int vtime;

void input()
{
  cin >> N >> M;
  adjacentList.resize(N);
  visited.resize(N);
  entryPoint.resize(N);
  lowPoint.resize(N);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    adjacentList[a - 1].push_back(b - 1);
    adjacentList[b - 1].push_back(a - 1);
  }
}

void dfs(int v, int p = -1)
{
  visited[v] = true;
  entryPoint[v] = lowPoint[v] = ++vtime;
  int children = 0;
  for (int to : adjacentList[v])
  {
    if (p == to)
      continue;
    if (visited[to])
    {
      lowPoint[v] = min(lowPoint[v], entryPoint[to]);
    }
    else
    {
      dfs(to, v);
      lowPoint[v] = min(lowPoint[v], lowPoint[to]);
      if (lowPoint[to] >= entryPoint[v] && p != -1)
      {
        curVertices.insert(v);
      }
      if (lowPoint[to] > entryPoint[v])
      {
        bridges.push_back({v, to});
      }
      children++;
    }
  }
  if (p == -1 && children > 1)
  {
    curVertices.insert(v);
  }
}

void traverse()
{
  // reset some data;
  vtime = 0;
  entryPoint.assign(N, -1);
  lowPoint.assign(N, -1);
  visited.assign(N, false);
  for (int i = 0; i < N; i++)
  {
    if (!visited[i])
    {
      dfs(i);
    }
  }
}

int main()
{
  // input:
  // Dong dau:
  //    SoDinh  SoCanh
  // Nhap cac canh:
  //    Dinh1   Dinh2
  input();
  traverse();
  cout << "Number of Cut vertices: " << curVertices.size() << "\nNumber of Bridges:" << bridges.size();
  cout << "\nCut vertices: ";
  for (auto i : curVertices)
  {
    cout << i << " ";
  }
  cout << "\nBridges: \n";
  for (auto i : bridges)
  {
    cout << i.first << " - " << i.second << endl;
  }
  cout << "Low array: ";
  for (auto i : lowPoint)
  {
    cout << i << " ";
  }
  cout << "\nNum array: ";
  for (auto i : entryPoint)
  {
    cout << i << " ";
  }
  return 0;
}
