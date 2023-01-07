#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int twoCount = 0;
	for (int i = 2; i <= n; i *= 2) {
		twoCount += n / i;
	}

	int fiveCount = 0;
	for (int i = 5; i <= n; i *= 5) {
		fiveCount += n / i;
	}

	if (twoCount > fiveCount) {	cout << fiveCount << '\n'; }
	else { cout << twoCount << '\n'; }


	 



	return 0;
}