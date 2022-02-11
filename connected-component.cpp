#include<bits/stdc++.h>
using namespace std;
vector<int> edge[1001];
vector<bool> visited(1001,false);
int cmp=0;
int n,m;
void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i <edge[u].size();i++)
    {
        if(!visited[edge[u][i]]) dfs(edge[u][i]);
    }
}
void input()
{
    cout<<"Nhap so dinh va so canh"<<endl;
    cin>>n>>m;
    cout<<"Nhap cac canh"<<endl;
    for(int i = 0; i <m;i++)
    {
    int a,b;
    cin>>a>>b;
    edge[a].push_back(b);
    edge[b].push_back(a);
    }
}
int main()
{
    // edge[1].push_back(2);
    // edge[1].push_back(3);
    // edge[2].push_back(1);
    // edge[2].push_back(3);
    // edge[3].push_back(4);
    // edge[4].push_back(6);
    // edge[4].push_back(9);
    // edge[5].push_back(6);
    // edge[5].push_back(8);
    // edge[5].push_back(11);
    // edge[6].push_back(4);
    // edge[6].push_back(5);
    // edge[6].push_back(7);
    // edge[6].push_back(9);
    // edge[7].push_back(6);
    // edge[7].push_back(9);
    // edge[7].push_back(10);
    // edge[8].push_back(5);
    // edge[8].push_back(11);
    // edge[9].push_back(4);
    // edge[9].push_back(6);
    // edge[9].push_back(7);
    // edge[10].push_back(7);
    // edge[11].push_back(5);
    // edge[11].push_back(8);
    input();
    for(int i = 1; i <=n;i++)
    {
        if(!visited[i])
        { 
            dfs(i);
            cmp++;
        }
    }
    cout<<cmp<<endl;
}
