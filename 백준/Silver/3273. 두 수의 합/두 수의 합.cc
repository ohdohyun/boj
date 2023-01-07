#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;

	sort(arr, arr + n);

	int st = 0, ed = n-1;
	int cnt = 0;
	
	while (st < ed) {
		//cout << arr[st] << ' ' << arr[ed] << '\n';
		if (arr[st] + arr[ed] == x) { cnt++; st++; ed--; }
		else if (arr[st] + arr[ed] < x) { st++; }
		else { ed--; }
	}
	cout << cnt << '\n';


	return 0;
}