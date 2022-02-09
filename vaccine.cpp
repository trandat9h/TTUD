#include <bits/stdc++.h>

using namespace std;
int x[8]; // x[0]: V, x[1]: A, x[2]: C, x[3]: I, x[4]: N, x[5]: E,x[6]: O, x[7]: D
int N;
int res = 0;
int choose[11];

bool check() {
	int sum = x[0] * 1000000 + x[1] * 100000 + x[2] * 11000 + x[3] * 100 + x[4] * 10
	+ x[5] - x[2] *  1000000 - x[6] * 100000 - x[0] * 10000 - x[3] * 1000 - x[7] *100 - 19;
	if (sum == N) {
		return true;
	}
	return false;
}

void solution(int u){
	if(u == 8) {
		if(check()) res++;
		return;
	}
	for(int i = 0; i <= 9; i++) {
		if(i == 0 && u <= 1) {
			continue;
		}
		if (choose[i]) {
			continue;
		}
		choose[i] = 1;
		x[u] = i;
		solution(u + 1);
		choose[i] = 0;
	}
}

int main() {
	memset(choose, 0, sizeof(choose));
	cin >> N;
	solution(0);
	cout << res;
}
