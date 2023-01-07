#include <iostream>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/4999



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string a, b;
	cin >> a >> b;

	if (a.length() < b.length()) {
		cout << "no\n";
	}
	else { cout << "go\n"; }

	return 0;
}