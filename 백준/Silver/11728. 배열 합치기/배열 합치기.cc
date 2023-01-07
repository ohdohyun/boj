#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/11728

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n + m; i++) {
		int input;
		cin >> input;

		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n + m; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	return 0;
}