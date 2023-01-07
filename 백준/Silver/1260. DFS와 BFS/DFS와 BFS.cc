#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[1001][1001];
int visited[1001];

int n, m, v;

void dfs(int v) {
	cout << v << ' ';
	visited[v] = 1;
	for (int i = 1; i <= n; i++) {
		if ((visited[i] == 1) || (arr[v][i] == 0)) { continue; }
		dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 0;

	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if ((visited[i] == 0) || (arr[v][i] == 0)) { continue; }
			q.push(i);
			visited[i] = 0;
		}
	}
	cout << '\n';
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	bfs(v);
	cout << '\n';

	return 0;
}