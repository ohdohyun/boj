#include <iostream>

using namespace std;

int arr[1000] = {};

int num(int n) {
	if (n < 100) {
		return 1;
	}

	int temp = (n % 100) / 10;

	if ( (n/100 + n%10) == temp * 2) {
		return 1;
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (num(i) == 1) {
			count++;
		}
	}

	cout << count << '\n';


	return 0;
}


