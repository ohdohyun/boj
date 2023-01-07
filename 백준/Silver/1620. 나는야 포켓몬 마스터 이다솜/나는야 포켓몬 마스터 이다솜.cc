#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/1620

string dictionary[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map <string, int> h;

	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		dictionary[i] = input;
		h[input] = i;
	}

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		if (input[0] >= '0' && input[0] <= '9') {
			cout << dictionary[stoi(input)] << '\n';
		}
		else {
			cout << h[input] << '\n';
		}
	}
	return 0;
}