#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int arr[26];
	for (int i = 0; i < 26; i++) { arr[i] = -1; }

	string input;
	cin >> input;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		
		int index = input[i] - 'a';

		if (arr[index] == -1) {
			arr[index] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}


