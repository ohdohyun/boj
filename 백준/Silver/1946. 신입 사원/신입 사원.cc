#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T-- != 0) {
		int n;
		cin >> n;
        
		vector<pair<int, int>> v;
        
		int maxnum = 100001;
		int count = 0;

		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back(pair(a, b));
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (v[i].second < maxnum) {
				maxnum = v[i].second;
				count++;
			}
		}
		cout << count << '\n';

	}

	

	return 0;
}
