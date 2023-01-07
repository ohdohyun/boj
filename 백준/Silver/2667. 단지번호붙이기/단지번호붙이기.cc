#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX 26

int n;
int arr[MAX][MAX];
int visited[MAX][MAX];
int adress = 0;
int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0,0, 1, -1 };

int bfs(int x, int y) {
	visited[x][y] = 1;													///// 단지의 첫 방문칸을 방문확인처리
	int count = 1;														///// count는 단지에 속하는 집의 수
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();	
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];									///// 큐에 있던 단지의 주소를 기준으로 상하좌우 확인
			int ny = cur.second + dy[i];

			if (nx<1 || nx>n || ny<1 || ny >n) { continue; }
			if (arr[nx][ny] == 0 || visited[nx][ny] == 1) { continue; }	///// 맵의 범위 밖, 집이 없는 자리, 방문한곳이면 넘김

			q.push({ nx,ny });											
			visited[nx][ny] = 1;
			count++;

			//cout << "방문경로 : " << nx << ' ' << ny << '\n';				///// 오류 확인용
		}


	}

	adress++;																///// 단지의 수 +1
	return count;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	cin >> n;

	for (int i = 1; i <= n; i++) {					///// 입력
		string input;
		cin >> input;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = input[j-1] - '0';
		}
	}

	vector<int> result;								///// 각 단지의 단지수를 저장할 큐

	for (int i = 1; i <= n; i++) {					
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 1 || arr[i][j] == 0) { continue; }		///// 방문한적 없고 새로운 단지의 발견이면 bfs() 실행
			result.push_back(bfs(i, j));
		}
	}

	

	cout << adress << '\n';
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}

	/*for (int i = 1; i <= n; i++) {									///// 입력 확인용
		for (int k = 1; k <= n; k++) {
			cout << arr[i][k] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}