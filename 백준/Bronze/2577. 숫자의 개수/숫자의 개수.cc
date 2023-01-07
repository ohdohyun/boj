#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int arr[10] = {};

	int mul = A * B * C;
	
	while (mul > 0) {
		int temp = mul % 10;
		mul /= 10;

		arr[temp]++;
	}


	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}



	return 0;
}


