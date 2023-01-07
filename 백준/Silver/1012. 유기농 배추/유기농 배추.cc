#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[50][50];


bool isChecked(int x, int y) {
	if (map[x][y] == 0) { return true; }
	return false;
}


void printMap() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

void worms(int x, int y, int m, int n) {
	if (x < 0 || x >= m) { return; }
	if (y < 0 || y >= n) { return; }
	if (map[x][y] == 0) { return; }

	map[x][y] = 0;
	worms(x - 1, y, m, n);
	worms(x + 1, y, m, n);
	worms(x, y + 1, m, n);
	worms(x, y - 1, m, n);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	while (!(T-- ==0)) {
		int m, n, k;
		cin >> m >> n >> k;


		int count = 0;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}


		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {

				if (map[x][y] == 1) {
					count++;
					worms(x, y, m, n);
				}

			}
		}

		cout << count << endl;

	}
	return 0;
}