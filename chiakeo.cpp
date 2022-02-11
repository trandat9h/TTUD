#include<bits/stdc++.h>
using namespace std;
int m,n,curr,num=0;
int ans[1001];
void input()
{
    cin>>m>>n;
    curr = m;
}

void chiakeo(int k)
{
    for(int i=0;i<=curr && i <=10 ;i++)
    {
            ans[k] =i;
            curr-=i;
            if(k == n && curr ==0) 
            {
                num++;
            }
            else if(k <n && curr >=0)
            {
                chiakeo(k+1);

            }
            curr+=i;
    }
}
int main()
{
    input();
    chiakeo(1);
    cout<<num<<endl;
    //sua lai dieu kien vong lap for(trong truong hop nay so keo khong qua 10)
}
