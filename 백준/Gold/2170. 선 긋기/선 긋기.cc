#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;				//

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > y) { swap(x, y); }
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());


	int start = v[0].first, end = v[0].second, sum = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first > end) {
			sum += (end - start);
			start = v[i].first;
			end = v[i].second;
		}
		else {
			end = max(end, v[i].second);
		}
	}

	sum += (end - start);

	cout << sum << '\n';

	return 0;
}