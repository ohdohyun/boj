#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int st = 0, ed = 0;
	int ans = 2000000001;
	while(ed != n){

		if (arr[ed] - arr[st] >= m) {
			ans = min(ans, arr[ed] - arr[st]);
			if (ans == m) { break; }
			st++;
		}
		else { ed++; }
	}

	cout << ans << '\n';

	return 0;
}