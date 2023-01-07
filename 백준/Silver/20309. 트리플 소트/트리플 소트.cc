#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/20309

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	bool result = true;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;

		if (i % 2 != input % 2) { result = false; break; }
	}

	if (result) { cout << "YES\n"; }
	else { cout << "NO\n"; }
	

	return 0;
}