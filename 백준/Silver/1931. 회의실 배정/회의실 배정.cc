#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, start, end;
	cin >> N;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(pair(start, end));
	}

	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	int endTime = 0;
	for (int i = 0; i < N; i++) {
		if (endTime <= v[i].first) {
			endTime = v[i].second;
			cnt++;
		}
	}

	cout << cnt << '\n';



	return 0;
}
