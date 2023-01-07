#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

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
	cin >> m;
	int input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (binary_search(arr, arr + n, input)) { cout << 1 << '\n'; }
		else { cout << 0 << '\n'; }
	}

	return 0;
}