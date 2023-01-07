#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// https://www.acmicpc.net/problem/2470
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st = 0, ed = n - 1;
	int ans1 = 0, ans2 = 0, ansSum = 2000000001;
	while (st < ed) {
		int sum = arr[st] + arr[ed];

		//cout << arr[st] << ", " << arr[ed] << " //// st, ed = " << st << ", " << ed << '\n';

		if (ansSum > abs(sum)) {
			ansSum = abs(sum);
			ans1 = arr[st]; ans2 = arr[ed];
			if (sum == 0) { break; }
		}

		if (sum < 0) {
			st++;
		}
		else if (sum > 0) { ed--; }
	}

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}