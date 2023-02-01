#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/
#define ll long long
ll arr[4000][4];
vector<ll> a, b;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a.push_back(arr[i][0] + arr[j][1]);
			b.push_back(arr[i][2] + arr[j][3]);
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	/*cout << "***** a출력 *****\n";
	for (auto e : a) {
		cout << e << '\n';
	}

	cout << "***** b출력 *****\n";
	for (auto e : b) {
		cout << e << '\n';
	}*/

	ll cnt = 0;
	for (auto e : a) {
		// upper lower bound를 통해서 공략해보자...
		// e가 -23이면 upper (22) - lower(23)
		// e<0 이면 e*(-1) - 1
		// e가 23 이면 upper (-24) - lower(-23)
		// e>0 이면 e*(-1) - 1 - lower(-23)

		/*cout << e << '\n';
		cout << "*-1 = " << e * (-1) << '\n';
		cout << "upper(" << e * (-1) << ") = " << upper_bound(b.begin(), b.end(), e * (-1)) - b.begin() << '\n';
		cout << "lower(" << e * (-1) << ") = " << lower_bound(b.begin(), b.end(), e * (-1)) - b.begin() << '\n';*/

		cnt += (upper_bound(b.begin(), b.end(), e * (-1)) - b.begin()) - (lower_bound(b.begin(), b.end(), e * (-1)) - b.begin());
	}

	cout << cnt << '\n';
	

	return 0;
}