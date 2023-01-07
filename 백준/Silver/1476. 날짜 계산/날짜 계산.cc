#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1476

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int e, s, m;
	cin >> e >> s >> m;

	int year = 1;
	while (!(e == s && s == m && e==1)) {
		e--; s--; m--; year++;
		if (e == 0) { e = 15; }
		if (s == 0) { s = 28; }
		if (m == 0) { m = 19; }
	}
	cout << year << '\n';

	return 0;
}