#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int arr[42] = {};
	int input, count = 0;

	for (int i = 0; i < 10; i++) {
		cin >> input;
		input %= 42;
		arr[input] = 1;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i]) {
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}


