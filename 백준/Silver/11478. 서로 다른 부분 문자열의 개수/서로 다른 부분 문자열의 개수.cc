#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
// https://www.acmicpc.net/problem/11478

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	int len = input.length();
	unordered_set<string> um;

	int cnt = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 1; i + j <= len; j++) {
			string s = input.substr(i, j);

			//cout << "now : " << i << ", " << j << " = " << s << '\n';
			if (um.find(s) == um.end()) {
				// 잘라낸 문자열이 해쉬에 없다면
				um.insert(s);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}