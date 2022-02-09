#include <iostream>
#include <vector>
 
using namespace std;
 
 
 
int main() {
	int dem = 0;
	int x1, x2, x3, x4, x5, x6, x7;
	for(int x1 = 1; x1 <= 20; x1++) {
		for(int x2 = 1; x2 <= 20; x2++) {
			for(int x3 = 1; x3 <= 20; x3++) {
				for(int x4 = 1; x4 <= 20; x4++) {
					for(int x5 = 1; x5 <= 20; x5++){
						for(int x6 = 1; x6 <= 20; x6++){
							for(int x7 = 1; x7 <= 20; x7++){
								
									if ((x1 + x2 + x3 + x4 + x5 + x6 + x7) == 20) {
										dem++;
									}
								
							}
						}
					}
				}
			}
		}
	}
	cout << dem;
}
