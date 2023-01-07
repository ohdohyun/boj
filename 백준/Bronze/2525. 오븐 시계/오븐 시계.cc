#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int h, m, plus;
	cin >> h >> m >> plus;
	
	h += plus / 60;
	m += plus % 60;
	if (m >= 60) { m -= 60; h++; }
	h %= 24;

	cout << h << ' ' << m << '\n';
	
	return 0;
}