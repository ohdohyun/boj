#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[100001];
int n, k;
int cur;

bool isPossible(int nn) {
	if (nn<0 || nn>100001) { return false; }
	if (map[nn] != 0) { return false; }
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	int time = 0;

	if (n == k) { cout << 0 << '\n'; return 0; }
	map[n] = 1;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		cur = q.front(); q.pop();

		int nn = cur + 1;
		if (nn == k) { cout << map[cur] << '\n'; break; }
		if (isPossible(nn)) { map[nn] = map[cur] + 1; q.push(nn); }
		nn = cur - 1;
		if (nn == k) { cout << map[cur] << '\n'; break; }
		if (isPossible(nn)) { map[nn] = map[cur] + 1; q.push(nn); }
		nn = cur * 2;
		if (nn == k) { cout << map[cur] << '\n'; break; }
		if (isPossible(nn)) { map[nn] = map[cur] + 1; q.push(nn); }
	}
	

	return 0;
}