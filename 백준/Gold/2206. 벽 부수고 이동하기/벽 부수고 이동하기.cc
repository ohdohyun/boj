#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000
bool map[MAX][MAX];
int visited[MAX][MAX][2];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0, 1,-1 };

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int row, col;
	cin >> row >> col;
	queue < pair<pair<int, int>, int>> q;

	string input;
	for (int i = 0; i < row; i++) {
		cin >> input;
		for (int j = 0; j < col; j++) { map[i][j] = input[j] - '0'; }
	}
	q.push({ {0, 0}, 0 });
	visited[0][0][0] = visited[0][0][1] = 1;
	
	while (!q.empty()) {
		pair<pair<int, int>, int > cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first.first + dr[i];
			int nc = cur.first.second + dc[i];
			if (nr < 0 || nr >= row || nc < 0 || nc >= col) { continue; }				///// 범위 밖의 부분일 때
			if (map[nr][nc] == 1 && cur.second == 0 && visited[nr][nc][cur.second + 1] == 0) {		///// 벽이고, 부순적 없고, 방문 안한 위치
				q.push({ {nr,nc}, cur.second + 1 });
				visited[nr][nc][cur.second + 1] = visited[cur.first.first][cur.first.second][cur.second] + 1;
			}

			if (map[nr][nc] == 0 && visited[nr][nc][cur.second] == 0 ) {		///// 벽이 아니고 방문을 안한 위치
				q.push({ {nr, nc}, cur.second });
				visited[nr][nc][cur.second] = visited[cur.first.first][cur.first.second][cur.second] + 1;
			}
			
			if (nr == row - 1 && nc == col - 1) {
				cout << visited[nr][nc][cur.second] << '\n';
				return 0;
			}
		}
	}
	
	if (row == 1 && col == 1) { cout << 1 << '\n'; }
	else { cout << -1 << '\n'; }

	return 0;
}