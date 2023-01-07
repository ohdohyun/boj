#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
// https://www.acmicpc.net/problem/1373

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;


	for (int i = 0; i < s.length(); i++) {
		string t = "";
		if (s[i] >= '4') {
			s[i] -= 4; t += '1';
		}
		else { if(i) t += '0'; }

		if (s[i] >= '2') {
			s[i] -= 2; t += '1';
		}
		else { t += '0'; }

		if (s[i] >= '1') {
			s[i] -= 1; t += '1';
		}
		else { t += '0'; }

		if (i) { cout << t; }
		else { cout << stoi(t); }
	}


	return 0;
}