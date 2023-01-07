#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/11576

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int future, now;
	cin >> future >> now;
	
	int m; cin >> m;
	int value = 1;
	for (int i = 0; i < m - 1; i++) {
		value *= future;
	}

	int sum = 0;
	while (m--) {
		int A;
		cin >> A;

		sum += value * A;
		value /= future;
	}

	stack<int> s;
	while (sum != 0) {
		s.push(sum % now);
		sum /= now;
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}



	return 0;
}