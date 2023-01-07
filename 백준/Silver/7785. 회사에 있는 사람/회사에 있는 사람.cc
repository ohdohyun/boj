#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
// https://www.acmicpc.net/problem/7785

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	unordered_set<string> s;
	while (n--) {
		string name, state;

		cin >> name >> state;
		if (state == "enter") { s.insert(name); }
		else if (s.find(name) != s.end() ) { s.erase(name); }
	}

	vector<string> v;

	for (auto e : s) {
		v.push_back(e);
	}
	sort(v.begin(), v.end(), greater<>() );
	for (auto e : v) { cout << e << '\n'; }


	return 0;
}