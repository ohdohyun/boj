#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/11441

int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i != 1) { arr[i] += arr[i - 1]; }
	}

	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;

		cout << arr[b] - arr[a - 1] << '\n';
	}


	return 0;
}