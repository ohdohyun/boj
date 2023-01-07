#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2293

long long room[1000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
	}

	long long total, sub;
	long long int sum = n;
	cin >> total >> sub;
	for (int i = 0; i < n; i++) {
		room[i] -= total;

		if (room[i] > 0) {
			sum += (room[i] / sub + 1);
			if (room[i] % sub == 0) { sum--; }
		}
	}
	cout << sum << '\n';
	


	return 0;
}