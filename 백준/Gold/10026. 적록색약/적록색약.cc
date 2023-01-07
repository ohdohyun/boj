#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define M 100
char map[M][M];
bool visited[M][M][2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;

void RGBbfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j][0] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
			if (visited[nx][ny][0] == 1) { continue; }
			if (map[cur.first][cur.second] != map[nx][ny]) { continue; }

			q.push({ nx,ny });
			visited[nx][ny][0] = 1;
		}
	}
}

bool isBlue(int i, int j) {
	if (map[i][j] == 'B') { return true; }
	return false;
}

void RGbfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j][1] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
			if (visited[nx][ny][1] == 1) { continue; }
			if (isBlue(cur.first, cur.second) != isBlue(nx,ny)) { continue; }

			q.push({ nx,ny });
			visited[nx][ny][1] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int RGB = 0, RG = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j][0] == 0) {
				RGBbfs(i, j);
				RGB++;
			}
			if (visited[i][j][1] == 0) {
				RGbfs(i, j);
				RG++;
			}
		}
	}

	cout << RGB << ' ' << RG;

	return 0;
}