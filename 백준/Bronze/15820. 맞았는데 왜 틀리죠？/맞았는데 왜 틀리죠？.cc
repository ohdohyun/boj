#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/15820
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int s1, s2;
	cin >> s1 >> s2;

	int isSample = 1, isSystem = 1;
	int input, ans;

	for (int i = 0; i < s1; i++) {
		cin >> input >> ans;
		if (input != ans) { isSample = 0; break; }
	}

	for (int i = 0; i < s2; i++) {
		cin >> input >> ans;
		if (input != ans) { isSystem = 0; break; }
	}

	if (isSample && isSystem) { cout << "Accepted\n"; }
	else if (isSample) { cout << "Why Wrong!!!\n"; }
	else { cout << "Wrong Answer\n"; }



	return 0;
}