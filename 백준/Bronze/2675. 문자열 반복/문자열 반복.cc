#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string input;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		int n;
		cin >> n >> input;

		int len = input.length();

		for (int k = 0; k < len; k++) {
			for (int j = 0; j < n; j++) {
				cout << input[k];
			}
		}
		cout << '\n';


	}

	return 0;
}


