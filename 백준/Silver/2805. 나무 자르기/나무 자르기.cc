#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2293

long long n, m;
vector<int> v;

long long returnSum(int height) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (v.at(i) > height) {
			sum += v.at(i) - height;
		}
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int f = 0, l = v.back();	
	long long cur;
	while (f < l) {
		int mid = (f + l) / 2;
		cur = returnSum(mid);
		if (cur == m) { cout << mid << '\n'; return 0; }
		//cout << f << ' ' << l << ", " << cur << '\n';

		if (cur < m) { l = mid; }
		else if (cur > m) { f = mid + 1; }

	}

	cout << f - 1 << '\n';
	return 0;
}