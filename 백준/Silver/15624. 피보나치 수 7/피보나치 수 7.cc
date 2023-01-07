#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	int n;
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 2] + arr[i - 1]) % 1000000007;
	}

	cout << arr[n] << '\n';



	return 0;
}