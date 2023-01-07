#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/16234

#define M 50
int map[M][M];
int visited[M][M];
int n, L, R;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

bool isUnited(int r, int c) {			// 연합 가능한 상태이면 true 리턴
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
		if (visited[nx][ny] == 1) { continue; }
		int sub = abs(map[r][c] - map[nx][ny]);
		if (sub >= L && sub <= R) { return true; }
	}
	return false;
}

void visitedClear(int n) {				// 방문한 좌표를 전부 0으로 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;

	queue<pair<int, int>> united;
	int unitedSum = map[r][c];						// 연합할 나라들의 인구수 총합저장, 최초 시작좌표로 초기화

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		united.push(cur);							// 연합할 나라들의 좌표 저장.

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			int sub = abs(map[cur.first][cur.second] - map[nx][ny]);
			if (sub < L || sub > R) { continue; }	
			q.push({ nx,ny });						// 연합가능하면 큐에 넣고 방문처리, 인구수 총합에 +
			visited[nx][ny] = 1;
			unitedSum += map[nx][ny];
		}
	}

	unitedSum /= united.size();						// 총합 나누기 연합국 수
	while (!united.empty()) {						// 전체 연합국 인구를 평균으로 초기화
		pair<int, int> cur = united.front(); united.pop();
		map[cur.first][cur.second] = unitedSum;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> L >> R;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int isMove = 1, day = 0;
	while (isMove) {
		isMove = 0;												// 하루를 시작하고 isMove를 0으로 초기화, 전체 다 돌았는데 그대로면 연합x
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isUnited(i, j) && visited[i][j] == 0) {		// 연합 가능하고 방문한적 없으면 bfs시작, isMove=1로 초기화
					bfs(i, j);
					isMove = 1;									// 하루 인구이동 가능
				}
			}
		}

		visitedClear(n);
		if (isMove == 1) { day++; }								// 연합 가능한곳이 있었다면 day++
	}
	
	cout << day << '\n';

}