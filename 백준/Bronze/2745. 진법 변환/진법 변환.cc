#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2745

int ctoi(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 10;
	}
	else { return c - '0';}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	int b;
	cin >> input >> b;
	
	int sum = 0;
	int value = 1;

	for (int i = input.size() - 1; i >= 0; i--) {
		sum += ctoi(input[i]) * value;
		value *= b;
	}

	cout << sum << '\n';
	return 0;
}