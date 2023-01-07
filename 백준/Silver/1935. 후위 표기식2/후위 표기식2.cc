#include <iostream>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/1935

double alphabet[26];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//double n = 12.3456789;
	//cout << floor(n *100)/100 << '\n';

	int n;
	cin >> n;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		cin >> alphabet[i];
	}

	stack<double> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			// 피연산자면 스택으로
			s.push(alphabet[str[i] - 'A']);
		}
		else {
			// 연산자면 필요한만큼 꺼내서 연산하고 연산결과 스택에 다시 넣기
			double a, b;
			a = s.top(); s.pop();
			b = s.top(); s.pop();

			if (str[i] == '+') { s.push(b + a);	}
			else if (str[i] == '-') { s.push(b - a); }
			else if (str[i] == '*') { s.push(b * a); }
			else if (str[i] == '/') { s.push(b / a); }
		}
	}

	cout.precision(2);
	cout << fixed << s.top() << '\n';

	return 0;
}