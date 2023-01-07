#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/12845

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;

	while (n--) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	int level = v.back();
	v.pop_back();

	int sum = 0;
	while (!v.empty()) {
		sum += level + v.back();
		v.pop_back();
	}

	cout << sum << '\n';

	return 0;
}