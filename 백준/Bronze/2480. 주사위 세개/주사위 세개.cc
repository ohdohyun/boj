#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2480

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input[3] = {};
	int m = 0;
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
		m = max(m, input[i]);
	}

	if (input[0] == input[1] && input[1] == input[2]) {
		cout << 10000 + 1000 * input[0] << '\n';
	}
	else if (input[0] == input[1]) {
		cout << 1000 + 100 * input[0] << '\n';
	}
	else if (input[1] == input[2]) {
		cout << 1000 + 100 * input[1] << '\n';
	}
	else if (input[0] == input[2]) {
		cout << 1000 + 100 * input[2] << '\n';
	}
	else {
		cout << 100 * m << '\n';
	}

	return 0;
}