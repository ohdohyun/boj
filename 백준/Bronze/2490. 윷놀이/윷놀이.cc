#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2480

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input;
	for (int t = 0; t < 3; t++) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			cin >> input;
			sum += input;
		}

		switch (sum) {
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
	}

	return 0;
}