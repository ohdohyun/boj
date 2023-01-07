#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2752

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input[3] = {};
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
	}
	sort(input, input + 3);
	for (int i = 0; i < 3; i++) {
		cout << input[i] << ' ';
	}

	return 0;
}