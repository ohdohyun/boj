#include<iostream>
#include<cmath>

using namespace std;

bool b[10001];

int main() {
	
	fill_n(b, 10001, 1);
	b[0] = b[1] = 0;
	int n,t;
    
    //////////10000까지 소수 구하는 에라토스테네스의 체
	for (int i = 2; i <= 10000; i++) {
		if (b[i] == 1) {
			for (int j = i * i; j <= 10000; j += i) {
				b[j] = 0;
			}
		}
	}

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = n / 2; i > 0; i--) {
			if (b[i] == 1 && b[n - i] == 1) {
				cout << i << " " << n - i << endl;
				break;
			}
		}

	}

}
