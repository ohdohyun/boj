#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = n; i > 0; i--) {

		for (int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << '\n';
	}



	return 0;
}