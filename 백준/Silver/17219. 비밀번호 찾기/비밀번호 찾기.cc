#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
// https://www.acmicpc.net/problem/17219

unordered_map<string, string> um;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string site, pawd;
		cin >> site >> pawd;

		um[site] = pawd;
	}

	for (int i = 0; i < m;i++) {
		string input;
		cin >> input;

		cout << um[input] << '\n';
	}


	return 0;
}