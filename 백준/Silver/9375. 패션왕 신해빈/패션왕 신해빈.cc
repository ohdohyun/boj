#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
// https://www.acmicpc.net/problem/9375

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		if (n == 0) { cout << 0 << '\n'; continue; }
		unordered_map<string, int> um;
		int result = 1;

		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;

			if (um.find(type) != um.end()) {
				// 이미 있는경우
				um[type] += 1;
			}
			else {
				um[type] = 1;
			}

		}

		unordered_map<string, int>::iterator it;
		for (it = um.begin(); it != um.end(); it++) {
			result *= (it->second) + 1;
		}

		cout << --result << '\n';
	}



	return 0;
}