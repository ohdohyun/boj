#include<iostream>
#include<cmath>

using namespace std;

bool b[246913];

int main() {
	
	fill_n(b, 246913, 1);
	b[0] = b[1] = 0;

	int n, count = 0;
	for (int i = 2; i * i <= 246912; i++) {
		if (b[i] == 1) {
			for (int j = 2; i * j <= 246912; j++) {
				b[i * j] = 0;
			}
		}
	}

	

	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		else {
			for (int i = n + 1; i <= 2 * n; i++) {
				if (b[i]) {
					count++;
				}
			}
			cout << count << endl;
			count = 0;
		}
	}




}
