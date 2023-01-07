#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/

int happy[1'000'001];
int unhappy[1'000'001];
int young_happy[1'000'001];
int young_unhappy[1'000'001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int young_h = 1'000'000'001, young_p = -1;
	for (int i = 1; i <= n; i++) {
		cin >> happy[i] >> unhappy[i];
		if (happy[i] != 0) {
			young_h = min(young_h, happy[i]);
		}
		if (unhappy[i] != 0) {
			young_p = max(young_p, unhappy[i]);
		}
		young_happy[i] = young_h;
		young_unhappy[i] = young_p;
	}
	
	int old_p = 1'000'000'001, old_h = -1;
	int cnt = -1;
	for (int k = n - 1; k >= 0; k--) {
		// k는 젊은 날, k+1은 늙은 날
		if (unhappy[k + 1] != 0) {
			old_p = min(old_p, unhappy[k + 1]);
		}
		if (happy[k + 1] != 0) {
			old_h = max(old_h, happy[k + 1]);
		}

		if (young_happy[k] > old_h && young_unhappy[k] < old_p) {
			cnt = max(cnt, k);
		}
	}

	cout << cnt << '\n';

	return 0;
}


