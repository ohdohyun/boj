#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, count = 0;
	int x, y, temp;
	cin >> N;

	if (N < 10) {
		x = 0;
		y = N;
	}
	else {
		x = N / 10;
		y = N % 10;
	}

	while (1) {
		count++;
		temp = x + y;
		x = y;
		y = temp % 10;

		if ((x * 10 + y) == N) { break; }

	}

	cout << count << '\n';

	return 0;
}


