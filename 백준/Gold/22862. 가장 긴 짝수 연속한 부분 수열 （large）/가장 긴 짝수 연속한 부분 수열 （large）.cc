#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/22862

int num[1'000'000];

int st = 0, ed = 0, len, cnt, m = 0;

void push() {
	ed++;
	(num[ed] % 2 == 0) ? len++ : cnt++;
}

void pull() {
	(num[st] % 2 == 0) ? len-- : cnt--;
	st++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	len = (num[0] % 2 == 0) ? 1 : 0;
	cnt = (num[0] % 2 == 0) ? 0 : 1;

	while (ed < n) {
		//cout << st << ", " << ed << " : len= " << len << ", cnt= " << cnt << '\n';
		
		// st == ed 이고 ed +1 < n 이면 ed++
		if (st == ed) {
			if (ed + 1 < n) {
				push();
			}
			else {
				m = max(m, len);
				break;
			}
		}
		else {
			if (ed + 1 >= n) { break; }
			if (cnt <= k) {
				push();
			}
			else {
				pull();
			}

		}

		m = max(m, len);
		//cout << m << '\n';
	}
	cout << m << '\n';




	return 0;
}