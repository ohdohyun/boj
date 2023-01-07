#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/17427

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	long long result = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		result += (n / i) * i;
	}
	cout << result << '\n';

	return 0;
}