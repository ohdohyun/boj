#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2109
// https://www.acmicpc.net/problem/1484


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int st = 1, ed = 1;

	int g = ed * ed - st * st;
	int isprint = 1;
	while (1) {

		if (ed * ed - st * st == n) { isprint = 0; cout << ed << '\n'; }
		if (ed - st == 1 && (ed * ed - st * st) > n) { break; }
		if (ed * ed - st * st > n) { st++; }
		else { ed++; }

	}

	if (isprint) { cout << -1 << '\n'; }

	return 0;
}