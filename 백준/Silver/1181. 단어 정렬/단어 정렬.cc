#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	vector<string> v;

	int N;
	string y;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> y;
		v.push_back(y);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		if (i > 0 && v[i] == v[i - 1]) {
			continue;
		}
		cout << v[i] << "\n";
	}



	return 0;
}