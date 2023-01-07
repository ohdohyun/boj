#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		for (int k = i; k < n; k++) {
			cout << ' ';
		}

		for (int k = 0; k < i; k++) {
			cout << "*";
		}


		cout << '\n';
	}



	return 0;
}


