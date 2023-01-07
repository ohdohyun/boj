#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/2573

#define M 300
int map[M][M];
int nextmap[M][M];
int visited[M][M];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int R, C;

int nearWater(int row, int col) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) { continue; }
		if (map[nx][ny] == 0) { count++; }
	}

	return count;
}

//nextmap에 빙산이 녹은 맵 저장
void nextYear() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) { 
			if (map[i][j] == 0) { continue; }
			nextmap[i][j] = map[i][j] - nearWater(i, j); 
			if (nextmap[i][j] < 0) { nextmap[i][j] = 0; }
		}
	}
}

// 녹은 맵을 원래 맵으로 가져옴
void nextmapTomap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) { map[i][j] = nextmap[i][j]; }
	}
}

//방문처리용
void bfs(int row, int col) {
	queue<pair<int, int>> q;
	q.push({ row, col });
	visited[row][col] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) { continue; }
			if (map[nx][ny] == 0 || visited[nx][ny] == 1) { continue; }

			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}

// 방문처리 초기화
void clearVisited() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) { visited[i][j] = 0; }
	}
}

//맵 개수 카운트
int countLand() {
	int count = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] >= 1 && visited[i][j] == 0) {
				count++;
				if (count > 1) { clearVisited(); return 2; }
				bfs(i, j);
			}
		}
	}
	clearVisited();
	return count;
}

void printMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	int year = 0;
	while (1) {
		
		int nowLand = countLand();
		//cout << nowLand << '\n';
		//printMap();
		if (nowLand >= 2) { cout << year << '\n'; break; }
		if (nowLand == 0) { cout << 0 << '\n'; break; }

		year++;
		nextYear();
		nextmapTomap();
	}

	return 0;
}