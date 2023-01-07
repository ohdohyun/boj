#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/1806

#define M 100000
int arr[M];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	int st = 0, ed = 0, sum = arr[0];
	int len = (sum >= s) ? 1 : 100001;

	while (ed != n) {
		
		//cout << st << ' ' << ed << " : " << sum << ", " << len << '\n';
		
		if (sum >= s) {
			len = min(len, ed - st + 1);
			sum -= arr[st];
			st++;
			if (len == 1) { break; }
		}
		else if (sum < s) { ed++; sum += arr[ed]; }
	}
	
	if (len == 100001) { cout << 0 << '\n'; }
	else { cout << len << '\n'; }

	return 0;
}