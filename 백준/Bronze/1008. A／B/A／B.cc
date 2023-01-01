#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/***** 백준 1000 *****/

	double a, b;

	while (1) {
		cin >> a >> b;
		if (a > 0 && b < 10 && b != 0)
			break;
		else
			continue;
	}

	cout.precision(15);
	cout << a / b;



	return 0;
}