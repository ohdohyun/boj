#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/15654

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;
	
	int cnt = 0;
	while (b > a) {
		if (b % 10 == 1) {
			b /= 10;
			cnt++;
		}
		else if (b % 2 == 0) {
			b /= 2;
			cnt++;
		}
		else { break; }
	}

	if (a == b) { cout << cnt + 1 << '\n'; }
	else { cout << -1 << '\n'; }

	return 0;
}