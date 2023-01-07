#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/10815


int arr[500000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m;
	cin >>m;
	int cmp;
	for (int i = 0; i < m; i++) {
		cin >> cmp;
		if (binary_search(arr, arr + n, cmp)) { cout << 1 << ' '; }
		else { cout << 0 << ' '; }
	}

	return 0;
}