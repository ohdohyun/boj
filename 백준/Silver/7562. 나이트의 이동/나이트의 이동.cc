#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 300
int map[MAX][MAX];
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void clear(int l) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			map[i][j] = 0;
		}
	}
}

int bfs(int sx, int sy, int ex, int ey, int l) {

	if (sx == ex && sy == ey) { return 0; }

	queue<pair<int, int>> q;
	q.push({ sx,sy });
	map[sx][sy] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l) { continue; }
			if (map[nx][ny] >= 1) { continue; }
			if ((nx == ex) && (ny == ey)) { return map[cur.first][cur.second]; }

			map[nx][ny] = map[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	while (T-- != 0) {
		
		int l, startx, starty, endx, endy;
		cin >> l;
		cin >> startx >> starty;
		cin >> endx >> endy;

		clear(l);
		cout << bfs(startx, starty, endx, endy, l) << '\n';
	}
	return 0;
}