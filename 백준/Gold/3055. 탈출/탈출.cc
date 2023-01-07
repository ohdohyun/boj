#include <iostream>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/3055

#define M 50
char map[M][M];
int visited[M][M];
int r, c;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
queue <pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> r >> c;

	pair<int, int> Hedgehog;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') { q.push({ i,j }); }
			else if (map[i][j] == 'S') { Hedgehog = { i,j }; }
		}
	}
	q.push(Hedgehog);
	visited[Hedgehog.first][Hedgehog.second] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		int isHedgehog = map[cur.first][cur.second] == 'S' ? 1 : 0;
		if (!isHedgehog) { visited[cur.first][cur.second] = 1; }

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) { continue; }
			if (visited[nx][ny] >= 1 || map[nx][ny] == 'X') { continue; }
			if (isHedgehog && map[nx][ny] == 'D') { cout << visited[cur.first][cur.second] << '\n'; return 0; }
			if (map[nx][ny] != '.') { continue; }
			if (isHedgehog == 0) {
				map[nx][ny] = '*';
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
			else {
				map[nx][ny] = 'S';
				visited[nx][ny] = visited[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}

		}
	}
	cout << "KAKTUS\n";



	return 0;
}