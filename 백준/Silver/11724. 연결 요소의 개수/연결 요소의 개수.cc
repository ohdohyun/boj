#include <iostream>
#include <algorithm>

using namespace std;

#define POINT 1001

int map[POINT][POINT];
int visited[POINT];
int n, m;

void dfs(int start) {

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1 || map[start][i] == 0) { continue; }	///// 방문한적 있거나 연결안된 요소들 건너뜀

		//cout << "현재 상황 : start =" << start << ", i=" << i << '\n';
		visited[i] = 1;												///// 나머지 전부 방문처리하고 dfs로 추가 연결요소들 처리
		dfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	int result = 0;

	for (int i = 1; i <= n; i++) {
		if (visited[i] >= 1) { continue; }							///// 방문한적 있는 노드면 pass

		visited[i] = 1;												///// 방문한적 없으면 방문처리하고 연결요소 +1, dfs()로 연결요소들 전부 방문처리
		result++;
		dfs(i);
	}

	cout << result << '\n';

	return 0;
}