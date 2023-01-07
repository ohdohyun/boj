#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1373

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	while (s.length() % 3 != 0) {
		s = '0' + s;
	}
	for (int i = 0; i < s.length(); i += 3) {
		int num = 0;
		if (s[i] == '1') { num += 4; }
		if (s[i + 1] == '1') { num += 2; }
		if (s[i + 2] == '1') { num += 1; }
		cout << num;
	}

	return 0;
}