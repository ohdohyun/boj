#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2576

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input;
	int m = 101, sum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> input;
		if (input % 2 == 1) {
			sum += input;
			m = min(m, input);
		}
	}

	if (sum == 0) { cout << -1 << '\n'; return 0; }
	cout << sum << '\n' << m << '\n';

	return 0;
}