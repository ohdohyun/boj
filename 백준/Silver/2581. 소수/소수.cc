#include<iostream> 
#include<cmath>
using namespace std;

int ifPrimeNum(int n) {
	bool b = true;
	if (n <= 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	else {
		for (int j = 2; j <= sqrt(n); j++) {
			b = 1;
			if (n % j == 0) {
				b = 0;
				break;
			}
		}
		if (b) {
			return true;
		}
		else {
			return false;
		}
	}
}
int main() {

	int min = 0, m, n, sum = 0;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (ifPrimeNum(i)) {
			if (min == 0) {
				min = i;
			}
			sum += i;
		}
	}

	if (sum > 0)
	{
		cout << sum << endl << min << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}

