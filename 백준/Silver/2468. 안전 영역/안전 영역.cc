#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/

int map[501][501];
int visited[501][501];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n;

void map_clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(int x, int y, int k) {
	queue<pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		//cout << cur_x << ", " << cur_y << " = " << map[cur_x][cur_y] << '\n';
		for (int i = 0; i < 4; i++) {
			int now_x = cur_x + dx[i];
			int now_y = cur_y + dy[i];

			if (now_x < 0 || now_x >= n || now_y < 0 || now_y >= n) { continue; }
			if (visited[now_x][now_y] == 1) { continue; }
			if (map[now_x][now_y] <= k) { continue; }

			q.push({ now_x, now_y });
			visited[now_x][now_y] = 1;
		}
	}
}

int safezone(int k) {

	int cnt = 0;
	for (int rain = 0; rain < k; rain++) {
		//cout << "########### k = " << rain << " #########\n";
		int safe = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > rain && visited[i][j] == 0) {
					bfs(i, j, rain);
					safe++;
				}
			}
		}
		cnt = max(cnt, safe);
		//print_map();
		//cout << "---- " << safe << '\n';
		map_clear();
	}
	return cnt;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	int highest = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			highest = max(highest, map[i][j]);
		}
	}

	cout << safezone(highest) << '\n';

	return 0;
}