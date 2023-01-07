#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/15656

int n, m;
int result[10];
int isused[10];
vector<int> numbers;
void rec(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << numbers[result[i] - 1] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			//isused[i] = 1;
			result[k] = i;
			rec(k + 1);
			//isused[i] = 0;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		numbers.push_back(input);
	}
	sort(numbers.begin(), numbers.end());
	rec(0);

	return 0;
}