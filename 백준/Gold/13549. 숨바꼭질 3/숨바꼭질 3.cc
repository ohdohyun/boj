#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/

using namespace std;

int n, k;
const int dx[2] = { -1, 1 };
bool visited[100010];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	q.push({ n, 0 });
	visited[n] = 1;
	for (int i = 2; i * n <= 100002; i *= 2) {
		if (n == 0) break;
		q.push({ i * n, 0 });
		visited[i * n] = 1;
	}
	while (!q.empty()) {
		auto cur = q.front();
		//cout << cur.first << " " << cur.second << '\n';
		q.pop();
		if (cur.first == k) {
			cout << cur.second << '\n';
			return 0;
		}
		for (int i = 0; i < 2; i++) {
			int nn = cur.first + dx[i];

			if (nn < 0 || (nn > 100000)) { continue; }
			if (visited[nn]) { continue; }

			q.push({ nn, cur.second + 1 });
			visited[nn] = 1;

			for (int i = 2; i * nn <= 100000; i *= 2) {
				if (nn == 0) { break; }
				if (visited[i * nn]) { continue; }
				q.push({ i * nn, cur.second + 1 });
				visited[i * nn] = 1;
			}
		}
	}


	return 0;

}