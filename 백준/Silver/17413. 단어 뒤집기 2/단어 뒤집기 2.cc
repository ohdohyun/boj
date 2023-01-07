#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	getline(cin, input);

	stack<char> s;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ' || (input[i] == '<' && !s.empty())) {
			// 띄어쓰기 또는
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			if (input[i] == '<') { i--; }
			else { cout << ' '; }
		}
		else if (input[i] == '<') {
			// 그대로 출력
			cout << input[i];
			i++;
			
			while (!(input[i] == '>')) {
				cout << input[i];
				i++;
			}
			cout << input[i];
		}
		else {
			// 스택에 저장
			s.push(input[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	
	return 0;
}