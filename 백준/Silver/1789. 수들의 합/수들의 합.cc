#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long s;
	cin >> s;

	int count = 0;
	for (int i = 1;; i++) {
		s -= i;
		if (s < 0) {
			cout << count << '\n'; return 0;
		}
		count++;
	}

}