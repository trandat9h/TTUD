#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool P(double x) {
	return pow(x, 19) - pow(x, 2) - x + 1 <= 0.0;
}
int main () {
	double eps = 0.000001, lo = 0.0, hi = 1.0, mid;
	while(hi - lo > eps) {
		mid = (lo + hi) / 2.0;
		if (P(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << mid;
}
