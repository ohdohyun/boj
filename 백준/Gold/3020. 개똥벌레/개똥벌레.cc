#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/3020

int b[100000], t[100000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, h;
	cin >> n >> h;

	for (int i = 0; i < n/2; i++) {
		cin >> b[i] >> t[i];
	}
	
	sort(b, b + n / 2);
	sort(t, t + n / 2);

	int ans = 200001;
	int num = 0;

	for (int i = 1; i <= h; i++) {
		int cnt = 0;

		int temp = lower_bound(b, b + n / 2, i) - b;
		cnt += n / 2 - temp;

		temp = upper_bound(t, t + n / 2, h - i) - t;
		cnt += n / 2 - temp;

		if (ans == cnt) { num++; }
		if (ans > cnt) { ans = cnt; num = 1; }
	}

	cout << ans << ' ' << num;


	return 0;
}