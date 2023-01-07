#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/6588

#define MAX 1000000
int arr[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fill(arr, arr + MAX + 1, 1);

	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 1) {
			for (int j = i * i; j <= 1000000; j += i) {
				arr[j] = 0;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		int cnt = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (arr[i] && arr[n - i]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}



	return 0;
}