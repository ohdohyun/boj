#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	

	while (T-- != 0) {

		string input;
		cin >> input;

		int count = 0;


		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(') {
				count++;
			}
			else if (input[i] == ')') {
				count--;
			}

			if (count < 0) {
				break;
			}
		}
		
		if (count == 0) { cout << "YES\n"; }
		else { cout << "NO\n"; }

	}

	

	return 0;
}
