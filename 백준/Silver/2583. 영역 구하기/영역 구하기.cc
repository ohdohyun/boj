#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2583

int map[101][101];
int a, b, c, d, n, m, k;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
vector<int> v;

void paint(int x1, int y1, int x2, int y2) {

	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			map[i][j] = 1;
		}
	}
}
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	map[x][y] = 1;
	int size = 1;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
            
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
			if (map[nx][ny] == 1) { continue; }

			q.push({ nx,ny });
			map[nx][ny] = 1;
			size++;
		}
	}
	v.push_back(size);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		cin >> a >> b >> c >> d;
		paint(a, b, c, d);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e << ' ';
	}

	return 0;
}