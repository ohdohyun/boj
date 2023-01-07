#include <iostream>
#include <algorithm>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	string input;
	cin >> input;
	int sum = 0;
	int len = input.length();

	for (int i = 0; i < len; i++) {
		if (input[i] <= 'C') {
			sum += 3;
		}
		else if (input[i] <= 'F') {
			sum += 4;
		}
		else if (input[i] <= 'I') {
			sum += 5;
		}
		else if (input[i] <= 'L') {
			sum += 6;
		}
		else if (input[i] <= 'O') {
			sum += 7;
		}
		else if (input[i] <= 'S') {
			sum += 8;
		}
		else if (input[i] <= 'V') {
			sum += 9;
		}
		else {
			sum += 10;
		}
	}


	cout << sum << '\n';

	return 0;
}


