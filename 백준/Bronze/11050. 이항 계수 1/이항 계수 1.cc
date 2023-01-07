#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int result = 1;
	int r = 1;
	for (int i = n - k + 1; i <= n; i++) {
		result *= i;
		result /= r++;
	}

	cout << result << '\n';
	
	return 0;
}