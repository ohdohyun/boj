#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1000][1000];
int visited[1000][1000];
int day = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isClear() {										///// 모든 토마토가 익었는지 확인하는 함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) { return false; }
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {						///// 입력
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {						///// 입력 하면서 익은 토마토를 큐에 푸쉬
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	///////////////// n -> i -> first -> nx
	///////////////// m -> j -> second -> ny


	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();		///// 익은 토마토를 cur에 저장하고 pop

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }		///// 맵 범위 밖이거나 안익은 토마토, 이미 방문한 토마토면 넘김
			if (map[nx][ny] == -1 || visited[nx][ny] == 1) { continue; }

			map[nx][ny] = map[cur.first][cur.second] + 1;					///// 이전 익은토마토(day) + 1을 저장
			day = map[cur.first][cur.second] + 1;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			//cout << "방문경로 : " << nx << ' ' << ny << '\n';
		}
	}


	if (isClear()) {
		if (day > 0) { cout << day - 1 << '\n'; }
		else { cout << 0 << '\n'; }
	}
	else { cout << -1 << '\n'; }




	/*cout << '\n';
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}*/


	return 0;
}