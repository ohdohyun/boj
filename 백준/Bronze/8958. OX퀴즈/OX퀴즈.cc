#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	
	string input;

	for (int i = 0; i < T; i++) {
		
		cin >> input;
		int len = input.length();
		int count = 0, sum = 0;
		for (int k = 0; k < len; k++) {
			if (input[k] == 'O') {
				count++;
				sum += count;
			}
			else { count = 0; }
		}


		input.clear();
		cout << sum << '\n';
	}

	return 0;
}


