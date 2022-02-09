#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    long n;
    cin >> n;
    long long temp;
    vector<long long> a;
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    s[0] = a[0];
    long long max = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i - 1] > 0) s[i] = s[i - 1] + a[i];
        else s[i] = a[i];
        max = max > s[i] ? max : s[i];
    }
    cout << max;
}
