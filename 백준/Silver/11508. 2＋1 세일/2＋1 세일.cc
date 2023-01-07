#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/11508


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) { v.pop_back(); }
		else { sum += v.back(); v.pop_back(); }
	}
	cout << sum << '\n';

	return 0;
}