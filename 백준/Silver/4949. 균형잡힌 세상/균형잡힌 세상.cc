#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

bool isSymmetry(string input) {
	int len = input.length();

	stack<char> s;
	for (int i = 0; i < len; i++) {
		if (input[i] == '(' || input[i] == '[') {
			s.push(input[i]);

		}
		else if (input[i] == ')') {
			if (s.empty()) { return false; }
			if (s.top() != '(') { return false; }
			s.pop();
		}
		else if (input[i] == ']') {
			if (s.empty()) { return false; }
			if (s.top() != '[') { return false; }
			s.pop();
		}
	}
	if (s.empty()) { return true; }
	return false;


}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string input;

	while (true) {
		getline(cin, input);
		if (input == ".") { break; }

		if (isSymmetry(input)) { cout << "yes\n"; }
		else { cout << "no\n"; }

	}
	
	return 0;
}