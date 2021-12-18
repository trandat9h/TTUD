
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int result, maxi;
    cin >> n;
    int *a = new int[n];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    if ( n == 1)
    {
        cout << a[0];
        return 0;
    }
    else
    {
        result = a[0];
        maxi = a[0];
        for (int i =1;i< n;i++)
        {
            maxi = max(maxi+a[i], a[i]);
            result = max(maxi, result);
        }
        cout << result;
        return 0;
    }
}
