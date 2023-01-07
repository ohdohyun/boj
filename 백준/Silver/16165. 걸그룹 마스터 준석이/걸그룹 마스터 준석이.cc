#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
// https://www.acmicpc.net/problem/16165

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> migo;			// member in group out
	unordered_map<string, vector<string>> gimo;	// group in member out

	for (int i = 0; i < n; i++) {
		string group;
		int size;
		cin >> group >> size;

		vector<string> mem;
		for (int j = 0; j < size; j++) {
			string member;
			cin >> member;
			mem.push_back(member);
			migo[member] = group;
		}
		gimo[group] = mem;
	}


	for (int i = 0; i < m; i++) {
		string question;
		int qnum;

		cin >> question >> qnum;

		if (qnum == 1) {
			cout << migo[question] << '\n';
		}
		else {
			vector<string> mem;
			mem = gimo[question];
			sort(mem.begin(), mem.end());
			for (auto e : mem) {
				cout << e << '\n';
			}
		}
	}

	return 0;
}