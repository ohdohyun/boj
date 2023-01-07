#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/12893

int visited[2001];
vector<int> human[2001];

bool bfs(int st) {
	visited[st] = 1;	// red=1, blue=2
	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		int cur_color = visited[cur];
		q.pop();

		for (auto e : human[cur]) {
			if(visited[e]==cur_color){
				return false;
			}
			else if(visited[e]==0){
				visited[e] = (cur_color == 1) ? 2 : 1;
				q.push(e);
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		human[a].push_back(b);
		human[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		// 1번째 사람부터 n번째 사람까지 전체 조사
		if (visited[i] == 0) {
			if (!bfs(i)) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	cout << 1 << '\n';

	return 0;
}