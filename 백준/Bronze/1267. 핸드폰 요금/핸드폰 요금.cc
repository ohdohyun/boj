#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1267

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int sum_y = 0;
	int sum_m = 0;
	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input % 30 == 29) {
			sum_y += input / 30 * 10;
		}
		else {
			sum_y += (input / 30 + 1) * 10;
		}
		if (input % 60 == 59) {
			sum_m += input / 60 * 15;
		}
		else {
			sum_m += (input / 60 + 1) * 15;
		}
	}

	if (sum_y < sum_m) {
		cout << "Y " << sum_y << '\n';
	}
	else if (sum_y > sum_m) {
		cout << "M " << sum_m << '\n';
	}
	else {
		cout << "Y M " << sum_y << '\n';
	}

	return 0;
}