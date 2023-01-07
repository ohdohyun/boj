#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1940

int arr[15'000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	sort(arr, arr + n);

	int st = 0, cnt = 0;
	while (arr[st] <= m / 2) {
		//cout << "st : " << st << ", arr[st] =" << arr[st] << ", arr[lower(m-arr[st])] : " << arr[lower_bound(arr, arr + n, m - arr[st]) - arr] << '\n';
		if (arr[lower_bound(arr, arr + n, m - arr[st]) - arr] == m - arr[st] && m - arr[st] != m / 2) { cnt++; }
		st++;
	}

	cout << cnt << '\n';

	return 0;
}