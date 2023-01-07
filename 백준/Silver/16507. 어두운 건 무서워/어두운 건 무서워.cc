#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2109
// https://www.acmicpc.net/problem/1484

int map[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int r, c, n;
	cin >> r >> c >> n;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int input;
			cin >> input;
			map[i][j] = map[i][j - 1] + input;
		}
	}


	while (n--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		int sum = 0;
		int size;
		if (r2 - r1 > 0) {
			if (c2 - c1 > 0) { size = (r2 - r1 + 1) * (c2 - c1 + 1); }
			else { size = r2 - r1 + 1; }
		}
		else { size = c2 - c1 + 1; }
		for (int i = r1; i <= r2; i++) {
			sum += map[i][c2] - map[i][c1 - 1];
		}
		cout << sum / size << '\n';

	}




	return 0;
}