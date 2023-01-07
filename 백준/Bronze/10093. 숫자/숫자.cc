#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long int a, b;
	cin >> a >> b;
	if (a > b) { swap(a, b); }
	else if (a == b) { cout << 0 << '\n'; return 0; }
	cout << b - a - 1 << '\n';
	
	for (a += 1; a < b; a++) {
		cout << a << ' '; 
	}

	return 0;
}