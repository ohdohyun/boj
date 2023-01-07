#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int k;
	cin >> k;

	stack<int> s;
	for (int i = 0; i < k; i++) {
		int input;
		cin >> input;
		if (input == 0) { s.pop(); }
		else { s.push(input); }
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << '\n';
	
	return 0;
}