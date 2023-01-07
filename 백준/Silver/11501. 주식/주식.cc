#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/11501

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> v, buy;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			v.push_back(input);
		}

		long long sum = 0;
		int m = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] < m) {
				sum += m - v[i];
			}
			else {
				m = v[i];
			}
		}
		cout << sum << '\n';
	}
	
	return 0;
}