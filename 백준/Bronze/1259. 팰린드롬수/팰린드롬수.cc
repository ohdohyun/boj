#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string n;

	while (true) {

		cin >> n;
		if (n == "0") { break; }

		int size = n.length();
		bool result = true;

		for (int i = 0; i <= size / 2; i++) {

			//cout << n[i] << ' ' << n[size - i-1] << '\n';

			if (n[i] != n[size - i-1]) { 
				result = false;
				cout << "no\n";
				break;
			}
		}
		if (result) { cout << "yes\n"; }
	}





	return 0;
}
