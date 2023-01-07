#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/10162

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	if (t % 10 != 0) { cout << -1 << '\n'; return 0; }
	int a = 0, b = 0, c = 0;
	while (t >= 300) {
		t -= 300;
		a++;
	}
	while (t >= 60) {
		t -= 60;
		b++;
	}
	while (t >= 10) {
		t -= 10;
		c++;
	}

	if (a || b || c) {
		cout << a << ' ' << b << ' ' << c << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}