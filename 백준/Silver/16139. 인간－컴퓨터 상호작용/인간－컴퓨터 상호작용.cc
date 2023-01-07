#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/16139

int subsum[2'000'001][26];
char str[2'000'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	int n, l, r;
	char a;

	cin >> str >> n;
	for (int i = 0; str[i] != 0; i++) {
		subsum[i + 1][str[i] - 'a'] = 1;
	}

	for (int i = 0; str[i + 1] != 0; i++) {
		for (int j = 0; j < 26; j++) {
			subsum[i + 2][j] += subsum[i + 1][j];
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> a >> l >> r;
		cout << subsum[r + 1][a - 'a'] - subsum[l][a - 'a'] << '\n';
	}

	
	return 0;
}