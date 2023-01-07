#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int result = 0;

void rec(int n, int r, int c) {

	

	int standard = pow(2, n - 1);

	if (r >= standard) {
		r -= standard;
		result += pow(standard, 2) * 2;
	}

	if (c >= standard) {
		c -= standard;
		result += pow(standard, 2);
	}
	
	if (standard == 1) { return; }
	
	rec(n - 1, r, c);

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, r, c;
	cin >> n >> r >>  c;

	rec(n, r, c);
	cout << result << '\n';
	

	return 0;
}