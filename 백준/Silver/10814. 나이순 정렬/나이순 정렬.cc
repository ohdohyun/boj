#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool cmp(const pair<int, string> &a, const pair<int, string>& b) {
	return a.first < b.first;
}
//
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	vector<pair<int ,string>> v;

	int N;
	int age;
	string name;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << "\n";
	}



	return 0;
}