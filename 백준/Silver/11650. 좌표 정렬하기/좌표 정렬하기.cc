#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, int>> v;

	int N;
	int x, y;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << "\n";
	}



	return 0;
}