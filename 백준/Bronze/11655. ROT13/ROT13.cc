#include <iostream>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/11655

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;

	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = (str[i] - 'A' + 13) % 26 + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		}
		
	}

	cout << str << '\n';

	return 0;
}