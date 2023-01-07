#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/4796

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int p, l, v;
	
	int n = 1;
	while (true) {
		cin >> p >> l >> v;
		if (p == 0 && l == 0 && v == 0) { break; }
		int result = 0;
		while (v > 0) {
			if (v >= l) {
				v -= l;
				result += p;
			}
			else if (v <= p) {
				result += v;
				v = 0;
			}
			else {
				result += p;
				v = 0;
			}
		}
		cout << "Case " << n++ << ": " << result << '\n';
	}

	return 0;
}