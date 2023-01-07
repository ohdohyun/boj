#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
// https://www.acmicpc.net/problem/10158

#define M 50
char map[M][M];
int visited[M][M];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int row, col;

int bfs(int i, int j) {			// 시작 위치로부터 모든 육지탐색, 마지막땅까지 거리 리턴
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;			// 시작위치를 시간 1로 다음위치를 +1시간 하면서 이동

	pair<int, int> cur;
	while (!q.empty()) {
		 cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= row || ny >= col) { continue; }
			if (visited[nx][ny] >= 1 || map[nx][ny] == 'W') { continue; }

			visited[nx][ny] = visited[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}

	return visited[cur.first][cur.second] - 1;			// 처음시작시간인 1을 빼주고 마지막 땅의 시간 리턴
}

void visitedClear() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visited[i][j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'L') { 
				result = max(result, bfs(i, j));
				visitedClear();
			}
		}
	}

	cout << result << '\n';

	return 0;
}