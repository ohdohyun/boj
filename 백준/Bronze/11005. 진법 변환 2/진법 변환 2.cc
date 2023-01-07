#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/11005

char itoc(int a) {
	if (a < 10) { return '0' + a; }
	else { return 'A' + a - 10; }
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, b;
	cin >> n >> b;

	string ans = "";

	while (n != 0) {
		//cout << n << ", " << n << ", " << n % b << '\n';
		ans += itoc(n % b);
		n /= b;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}