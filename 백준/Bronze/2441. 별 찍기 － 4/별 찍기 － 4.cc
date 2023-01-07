#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2441

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n - i; j < n; j++) {
			cout << " ";
		}
		for (int j = i; j < n; j++) {
			cout << "*";
		}
		
		cout << '\n';

	}

	return 0;
}