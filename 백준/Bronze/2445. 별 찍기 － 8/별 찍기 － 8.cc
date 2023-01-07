#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2445

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < j; i++) {
			cout << "*";
		}
		for (int i = 0; i < 2 * (n - j); i++) {
			cout << " ";
		}
		for (int i = 0; i < j; i++) {
			cout << "*";
		}
		cout << '\n';
	}
	for (int j = n - 1; j >= 1; j--) {
		for (int i = 0; i < j; i++) {
			cout << "*";
		}
		for (int i = 0; i < 2 * (n - j); i++) {
			cout << " ";
		}
		for (int i = 0; i < j; i++) {
			cout << "*";
		}
		cout << '\n';
	}



	return 0;
}