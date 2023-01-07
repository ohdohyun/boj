#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	int cnt = 1, sum = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i] == '(') {
			cnt++;
		}
		else if (input[i-1] == ')') {
			sum++;
			cnt--;
		}
		else {
			sum += --cnt;
		}
	}

	cout << sum << '\n';
	
	return 0;
}