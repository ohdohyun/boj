#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2109
// https://www.acmicpc.net/problem/1484

int d[10001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int price, day;
		cin >> price >> day;

		v.push_back({ price, day });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int price = v.back().first;
		int day = v.back().second;
		v.pop_back();

    while(d[day] != 0 && day>0){day--;}

    d[day] = price;
	}

	int sum = 0;
	for (int i = 1; i <= 10000; i++) {
		sum += d[i];
	}

	cout << sum << '\n';

	return 0;
}