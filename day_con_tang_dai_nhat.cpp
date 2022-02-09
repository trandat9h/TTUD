#include<bits/stdc++.h>
using namespace std;
const int MAX = 10005;
int n;
int a[MAX];
int S[MAX];
int res;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

// ham kiem tra dieu kien de tang len
bool check(int a, int b) {
	bool flag1 = false, flag2 = false;
	if ((a < 0 && b > 0) || (a > 0 && b < 0)) flag1 = true; // trai dau
		if (abs(a) < abs(b)) flag2 = true; // tang ngat
	return flag1 & flag2;
}

void solve(){
    S[0] = 1;
    res = S[0];

    for(int i=1; i<n-1; i++){
        S[i] = 1;

        for(int j=0; j<i; j++){
            if(check(a[j], a[i])){
                if(S[i] < S[j] + 1){
                    S[i] = S[j] + 1;
                }
            }
        }

        res = max(res, S[i]);
    }

}

int main(){
    input();
    solve();

    cout << res;
    return 0;
}
