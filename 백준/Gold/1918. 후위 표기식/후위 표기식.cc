#include <iostream>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/1935

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str = "a";

	cin >> str;

	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			// 피연산자면 출력
			cout << str[i];
		}
		else if (str[i] == '(' || s.empty() || (s.top() == '(' && str[i] != ')')) {
			// '(' 이거나 스택이 비었거나 s.top이 '('이면 무조건 push
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			// ')' 이면 str[i] == '(' 까지 출력, pop
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (str[i] == '+' || str[i] == '-') {
			// '+', '-' 면 앞의 연산자가 '(' 일 때 까지 뺌
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			// str[i] 가 '*' 이거나 '/' 일 경우 앞의 연산자가 '(' 이거나 '+', '-' 일때까지 뺌
			while (!s.empty() && (s.top() != '(' && s.top() != '+' && s.top() != '-')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';



	return 0;
}