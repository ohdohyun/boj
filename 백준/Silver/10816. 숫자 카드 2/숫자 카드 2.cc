#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/10816

int arr[500000];
int n, input;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> input;
		cout << upper_bound(arr, arr+n, input) - lower_bound(arr,arr+n,input) << ' ';
	}

	return 0;
}