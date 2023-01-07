#include <iostream>

using namespace std;

int arr[10001] = {};


int d(int n) {
	int res = n;
	if (n >= 1000) { res = res + n / 1000; n %= 1000; }
	if (n >= 100) { res = res + n / 100; n %= 100; }
	if (n >= 10) { res = res + n / 10; n %= 10; }
	if (n >= 1) { res += n; }
	
	if (res < 10001) {
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int temp;

	for (int i = 1; i < 10000; i++) {
		temp = d(i);
		if (temp < 10001) {
			arr[temp] = 1;
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) {
			cout << i << '\n';
		}
	}


	return 0;
}


