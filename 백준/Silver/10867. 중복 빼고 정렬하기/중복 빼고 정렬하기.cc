#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2583

bool plu[1001];
bool minu[1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) { 
		int a; cin >> a;
		if (a < 0) { minu[abs(a)] = 1; }
		else { plu[a] = 1; }
	}

	for (int i = 1000; i >= 0; i--) {
		if (minu[i] == 1) {
			cout << -1 * i << ' ';
		}
	}

	for (int i = 0; i < 1001; i++) { 
		if (plu[i] == 1) {
			cout << i << ' ';
		}
	}
	
	return 0;
}