#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/
// https://www.acmicpc.net/problem/12852

#define M 100001
int arr[M];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) { arr[i] = i; }

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j * j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}

	cout << arr[n];

	return 0;
}