#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/2559

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[i];
	}
	//cout << sum << '\n';

	int st = 0, ed = k;
	int m = sum;
	while (ed < n) {
		sum -= arr[st];
		sum += arr[ed];
		st++;
		ed++;
		m = max(m, sum);
		//cout << "st, ed : " << st << ", " << ed << ", sum= " << sum << '\n';
		
	}

	cout << m << '\n';
	



	return 0;
}