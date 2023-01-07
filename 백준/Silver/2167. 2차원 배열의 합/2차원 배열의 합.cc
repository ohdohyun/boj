#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/2167

int arr[301][301];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	int k;
	cin >> k;

	while (k--) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int sum = 0;
		for (int i = y1; i <= y2; i++) {
			sum += arr[i][x2] - arr[i][x1-1];
		}

		cout << sum << '\n';
	}


	return 0;
}