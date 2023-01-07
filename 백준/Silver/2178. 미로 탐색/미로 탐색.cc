#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int arr[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int result = 0;


void bfs(int r, int c) {
	queue<pair<int, int>> q;

	visited[r][c] = 1;
	q.push({ r,c });
	arr[r][c] = 1;	//시작점 1로 카운트시작


	while (!q.empty()) {

		pair<int, int> cur = q.front(); q.pop();		//큐에 있던 값 cur로 저장하고 pop

		for (int i = 0; i < 4; i++) {
			int r = cur.first + dx[i];
			int c = cur.second + dy[i];

			if (r < 0 || r >= n || c < 0 || c >= m) { continue; }		// 맵 밖으로 나갈려하면 컷
			if (arr[r][c] == 0 || visited[r][c] == 1) { continue; }		// 길이 없거나 방문했으면 컷
			
			arr[r][c] = arr[cur.first][cur.second] + 1;					// 이전 위치 +1을 현재위치에 저장
			visited[r][c] = 1;											// 방문 표시
			q.push({ r, c });

			//cout << "현재 위치 : " << cur.first << ' ' << cur.second << ' ' << arr[n - 1][m - 1] << '\n';
		}
		

	}

	cout << arr[n - 1][m - 1] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	//////////////////// input ////////////////////
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < m; j++) {
			arr[i][j] = input[j] - '0';			// 문자 '0'의 아스키코드값을 빼서 숫자 0, 1로 변환
		}
	}

	bfs(0, 0);


	return 0;
}