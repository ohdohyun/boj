#include <iostream>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string input;
	cin >> input;

	int arr[26] = {};

	int len = input.length();

	for (int i = 0; i < len; i++) {
		if (input[i] >= 97) { input[i] -= 32; }
		arr[input[i] - 'A']++;
	}

	int max = -1;
	char maxChar = NULL;

	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			maxChar = '?';
		}
		else if (arr[i] > max) {
			maxChar = i + 'A';
			max = arr[i];
		}
	}

	cout << maxChar << '\n';


	return 0;
}


