#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/

#define M 100002
#define next nx[i]
int day[M];
int pos[M];
int subin, bro;

void printRoute() {
	stack<int> s;

	int cur = bro;
	s.push(bro);
	while (cur != subin) {
		cur = pos[cur];
		s.push(cur);
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start); day[start] = 1;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == bro) {
			//정답처리
			cout << day[cur] - 1 << '\n';
			printRoute();
			return;
		}
		int nx[3] = { cur + 1, cur - 1, cur * 2 };

		for (int i = 0; i < 3; i++) {
			if (next < 0 || next > M) { continue; }
			if (day[next] >= 1) { continue; }

			day[next] = day[cur] + 1;
			pos[next] = cur;
			q.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> subin >> bro;

	bfs(subin);
	
	return 0;
}