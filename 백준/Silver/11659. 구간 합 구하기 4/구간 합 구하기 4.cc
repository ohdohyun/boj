#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/11659

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	cin >> arr[1];
	for (int i = 2; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}	

	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << arr[y] - arr[x - 1] << '\n';
	}

	return 0;
}