#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int best = INT_MIN;
	for (int i = 0; i < n; i ++) {
	    for (int j = i; j < n; j ++) {
	        int sum = 0;
	        for (int k = i; k <= j; k ++) {
	            sum += arr[k] * arr[k] * arr[k];
	        }
	        best = max(best, sum);
	    }
	}	
	cout << best;
}
