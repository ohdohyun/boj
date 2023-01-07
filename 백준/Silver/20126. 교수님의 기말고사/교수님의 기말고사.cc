#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int n, m, s;
	cin >> n >> m >> s;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back({ start, start + end });
	}
	v.push_back({ s,s });
	v.push_back({ 0,0 });

	sort(v.begin(), v.end());

	for (int i = 0; i < n+2; i++) {
		if ((v[i + 1].first - v[i].second) >= m) { cout << v[i].second << '\n'; return 0; }
	}
	cout << -1 << '\n';


	return 0;
}