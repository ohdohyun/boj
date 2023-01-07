#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/2089

void solve(int N, bool isNegative) {
	if (N == 0)
		return;
	if (N == 1 && !isNegative) {
		printf("1");
		return;
	}
	if (N == 1 && isNegative) {
		printf("11");
		return;
	}
	if (N % 2 == 0) {
		solve(N / 2, !isNegative);
		printf("0");
	}
	else {
		if (!isNegative) // 다음 digit은 negative
			solve((N - 1) / 2, !isNegative);
		else
			solve((N + 1) / 2, !isNegative);
		printf("1");
	}
}	// BaaaaaarkingDog

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input;
	cin >> input;

	if (input == 0) { cout << 0 << '\n'; }
	else { solve(input, 0); }
	
	return 0;
}