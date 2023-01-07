#include <iostream>
#include <algorithm>
using namespace std;

int input[8];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 8; i++) {
		cin >> input[i];
	}

	int ascending = 1;
	for (int i = 0; i < 8; i++) {
		if (input[i] != i + 1) { ascending = 0; break; }
	}

	if (ascending) { cout << "ascending" << '\n'; return 0; }
	int descending = 1;
	for (int i = 0; i < 8; i++) {
		if (input[i] != 8 - i) { descending = 0; break; }
	}
	if (descending) { cout << "descending" << '\n'; return 0; }

	cout << "mixed" << '\n';

	return 0;
}