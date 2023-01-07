#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/10039

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 5;
	int sum = 0;
	while (t--) {
		int n;
		cin >> n;

		if (n < 40) { sum += 40; }
		else { sum += n; }
	}

	cout << sum / 5 << '\n';

	return 0;
}