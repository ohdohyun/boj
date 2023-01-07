#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/11931

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	while (n--) {
		int input; cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), greater());
	for (auto e : v) {
		cout << e << '\n';
	}

	return 0;
}