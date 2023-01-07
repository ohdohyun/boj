#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cin.ignore();

	while (n--) {

		string input;
		getline(cin, input);
		input += ' ';
		
		stack<char> s;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ' ') {
				while (!s.empty()) { cout << s.top();  s.pop(); }
				cout << input[i];
			}
			else {
				s.push(input[i]);
			}
		}
	}

	return 0;
}