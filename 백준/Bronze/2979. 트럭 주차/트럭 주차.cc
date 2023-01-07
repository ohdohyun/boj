#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2979

int arr[101];
int s[3], e[3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;


	for (int i = 0; i < 3; i++) {
		cin >> s[i] >> e[i];
		for (int j = s[i]; j < e[i]; j++) { arr[j]++; }
	}

	for (int i = 1; i <= 100; i++) {
		// cout << arr[i] << '\n';
	}


	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		switch (arr[i]) {
		case 1:
			sum += a;
			break;
		case 2:
			sum += 2 * b;
			break;
		case 3:
			sum += 3 * c;
			break;
		}

		//cout << arr[i] << ", " << sum << '\n';
	}
	
	cout << sum << '\n';


	return 0;
}