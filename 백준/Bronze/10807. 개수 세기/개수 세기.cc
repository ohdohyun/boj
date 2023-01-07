#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/10807
int negative[101], positive[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int input;
		cin >> input;
		if (input < 0) {
			input *= -1;
			negative[input]++;
		}
		else {
			positive[input]++;
		}
	}
	int find;
	cin >> find;

	if (find < 0) {
		find *= -1;
		cout << negative[find] << '\n';
	}
	else {
		cout << positive[find] << '\n';
	}
	
	return 0;
}