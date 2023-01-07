#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define M 1000
#define X first.first
#define Y first.second
char map[M][M];
int r, c;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	queue<pair<pair<int, int>, int>> q;
	pair<pair<int, int>, int> cur;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') { cur = { {i,j}, 1 }; }
			if (map[i][j] == 'F') { q.push({ { i,j }, 0 }); }	// 불이면 큐에 바로 넣어버리고 지훈이면 cur에 임시저장
		}
	}

	q.push(cur);	//불을 모두 넣은 뒤 지훈을 큐에 push

	while (!q.empty()) {
		cur = q.front(); q.pop();

		if (cur.second >= 1) {		// 지훈
			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) { cout << cur.second << '\n'; return 0; }		// 탈출?
				if (map[nx][ny] != '.') { continue; }

				q.push({ {nx,ny}, cur.second + 1 });
				map[nx][ny] = 'J';
			}
		}
		else {						// 불
			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) { continue; }
				if (map[nx][ny] == '#') { continue; }

				q.push({ {nx,ny}, 0 });
				map[nx][ny] = '#';
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}