#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2501

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) { cnt++; }
		if (cnt == k) { cout << i << '\n'; return 0; }
	}

	cout << 0 << '\n';
	
	return 0;
}