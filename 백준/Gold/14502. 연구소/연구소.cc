#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/14502

#define M 8
int map[M][M];
int temp[M][M];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int row, col;
vector<pair<int, int>> virus, safe;
void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) { 
		q.push(virus[i]); 
		temp[virus[i].first][virus[i].second] = 1;
	}

	while (!q.empty()) {
		pair<int,int> cur = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col) { continue; }
			if (temp[nx][ny] == 1) { continue; }

			q.push({ nx,ny });
			temp[nx][ny] = 1;
		}
	}
}

void mapToTemp() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) { temp[i][j] = map[i][j]; }
	}
}

int safeZone() {
	int result = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) { 
			if (temp[i][j] == 0) { result++; }
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) { 
			cin >> map[i][j];
			if (map[i][j] == 2) { virus.push_back({ i,j }); }
			else if (map[i][j] == 0) { safe.push_back({ i,j }); }
		}
	}

	int answer = 0;
	int size = safe.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				mapToTemp();									// map을 temp로 복사해오기
				temp[safe[i].first][safe[i].second] = 1;		// 벽 3개 세우기
				temp[safe[j].first][safe[j].second] = 1;
				temp[safe[k].first][safe[k].second] = 1;
				bfs();											// 바이러스 퍼트리기
				answer = max(answer, safeZone());
			}
		}
	}

	cout << answer << '\n';

	return 0;
}