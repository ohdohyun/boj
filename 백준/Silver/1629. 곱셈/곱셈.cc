#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long POW(long long a, long long b, long long c) {
	if (b == 1) { return a % c; }
	long long temp = POW(a, b / 2, c);
	temp = temp * temp % c;
	if (b % 2 == 0) { return temp; }
	return temp * a % c;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);

	return 0;
}