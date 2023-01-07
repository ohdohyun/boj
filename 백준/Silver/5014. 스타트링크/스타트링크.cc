#include <iostream>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/5014

#define M 1000001
int map[M];
int F, S, G, U, D;

int bfs() {
	if (S == G) { return 0; }
	queue<int> q;
	q.push(S);
	map[S] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		int nd = cur - D;
		int nu = cur + U;

		if (nd == G || nu == G) { return map[cur]; }
		if (nd > 0 && map[nd] == 0) {
			q.push(nd);
			map[nd] = map[cur] + 1;
		}
		if (nu <= F && map[nu] == 0) {
			q.push(nu);
			map[nu] = map[cur] + 1;
		}
	}

	return -1;

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> F >> S >> G >> U >> D;

	int result = bfs();
	if (result == -1) {
		cout << "use the stairs\n";
	}
	else { cout << result << '\n'; }
	
	return 0;
}