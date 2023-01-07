#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.second.second < b.second.second;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<pair<int,pair<int, int>>> v;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back({ input, {i, i} });
	}

	sort(v.begin(), v.end());

	v[0].second.first = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) { v[i].second.first = v[i - 1].second.first; }
		else { v[i].second.first = v[i - 1].second.first + 1; }
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << v[i].second.first << ' ';
	}

	/*for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << '\n';
	}*/

	return 0;
}