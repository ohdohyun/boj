#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/1339

int alphabet[26] = {};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	string input;
	cin >> n;
	vector<pair<int, char>> v;
	for (int i = 0; i < n; i++) {
		cin >> input;
		int len = input.length();

		for (int j = 0; j < len; j++) {
			alphabet[input[j] - 'A'] += pow(10, len - j - 1);
			//cout << input[j] << " : " << alphabet[input[j] - 'A'] << '\n';
		}
	}

	for (int j = 0; j < 26; j++) {
		if (alphabet[j] > 0) { v.push_back({ alphabet[j], j + 'A' }); }
	}
	sort(v.begin(), v.end());

	int s = v.size();
	for (int i = 0; i < s; i++) {
		// 9-i로 alphabet값을 지정
		alphabet[v.back().second - 'A'] *= 9 - i;
		v.pop_back();
	}

	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) { sum += alphabet[i]; }
		//cout << (char)(i + 'A') << " : " << alphabet[i] << '\n';
	}

	cout << sum << '\n';

	return 0;
}