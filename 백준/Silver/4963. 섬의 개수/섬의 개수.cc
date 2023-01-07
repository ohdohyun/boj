#include <iostream>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/4963

#define M 50
bool map[M][M];
int row, col;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 }, dy[8] = { 0,0,1,-1,1,-1,-1,1 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	map[i][j] = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col) { continue;	}
			if (map[nx][ny] == 0) { continue; }

			map[nx][ny] = 0;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while (1) {

		cin >> col >> row;
		if (row == 0 && col == 0) { break; }

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> map[i][j];
			}
		}

		int count = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					count++;
				}
			}
		}
		cout << count << '\n';
	}

	return 0;
}