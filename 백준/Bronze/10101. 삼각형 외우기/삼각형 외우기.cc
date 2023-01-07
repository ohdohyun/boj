#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2293

long long n, m;
vector<int> v;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (a + b + c != 180) { cout << "Error\n"; }
	else if (a == b && b == c) { cout << "Equilateral\n"; }
	else if (a == b || b == c || a == c) { cout << "Isosceles\n"; }
	else { cout << "Scalene\n"; }
	return 0;
}