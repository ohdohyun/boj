#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2587

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input[5], sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
		sum += input[i];
	}
	sort(input, input + 5);
	cout << sum / 5 << '\n' << input[2] << '\n';

	
	return 0;
}