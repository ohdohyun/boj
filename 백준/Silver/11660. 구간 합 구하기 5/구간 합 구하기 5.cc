#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/11659

int arr[1025][1025];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (j != 1) { arr[i][j] += arr[i][j - 1]; }
		}
	}

	while (m--) {
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int sum = 0;
		for (int i = y1; i <= y2; i++) {
			sum += arr[i][x2] - arr[i][x1 - 1];
		}
		cout << sum << '\n';
	}

	return 0;
}