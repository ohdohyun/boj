#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[100][100][100];
int dheight[6] = { 1, -1, 0, 0, 0, 0 };
int drow[6] = { 0, 0, 1, -1, 0, 0 };
int dcol[6] = { 0, 0, 0, 0, 1, -1 };
int result = 0;
int row, col, height;
queue<pair<pair<int, int>, int>> q;

void bfs() {
	

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front(); q.pop();
		result = max(result, map[cur.first.first][cur.first.second][cur.second]);

		for (int i = 0; i < 6; i++) {
			int nh = cur.first.first + dheight[i];			// a = height = first.first
			int nr = cur.first.second + drow[i];			// b = row = first.second
			int nc = cur.second + dcol[i];					// c = col = second

			if (nh < 0 || nh >= height || nr < 0 || nr >= row || nc < 0 || nc >= col) { continue; }		// 맵 범위 밖이면 넘어감
			if (map[nh][nr][nc] >= 1 || map[nh][nr][nc] == -1) { continue; }							// 이미 익은 토마토가 있거나(visited) 빈칸이면 넘어감

			map[nh][nr][nc] = map[cur.first.first][cur.first.second][cur.second] + 1;					// 이전칸 + 1을 map에 저장
			q.push({ {nh,nr}, nc });
		}
	}

}

bool is_there_zero() {
	for (int a = 0; a < height; a++) {
		for (int b = 0; b < row; b++) {
			for (int c = 0; c < col; c++) {
				if (map[a][b][c] == 0) { return true; }
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> col >> row >> height;

	for (int a = 0; a < height; a++) {									
		for (int b = 0; b < row; b++) {
			for (int c = 0; c < col; c++) {
				cin >> map[a][b][c];
				if (map[a][b][c] == 1) { q.push({ {a,b}, c }); }		// 입력 받으면서 토마토가 있는 칸은 바로 push
			}
		}
	}

	bfs();


	/*cout << '\n' << '\n';
	for (int a = 0; a < height; a++) {
		for (int b = 0; b < row; b++) {
			for (int c = 0; c < col; c++) {
				cout << map[a][b][c] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}*/

	if (is_there_zero()) {					// 아직도 안익은 토마토가 존재하면 (Map에 0이 있다면) -1출력
		cout << -1 << '\n';
		return 0;
	}

	cout << result - 1 << '\n';
	
	return 0;
}