#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/15659

int n, minNum = 2147483647, maxNum = -2147483647;
int numArr[11];
int op[4];

int calc(string ops) {
	// 계산식 구현
	//cout << "이게 연산순서고 : " << ops << '\n';
	vector<int> v;
	string pm = "";
	int len = ops.length();
	v.push_back(numArr[0]);
	for (int i = 0; i < len; i++) {
		if (ops[i] == '+') {
			pm += "+";
			v.push_back(numArr[i + 1]);
		}
		else if (ops[i] == '-') {
			pm += "-";
			v.push_back(numArr[i + 1]);
		}
		else if (ops[i] == '*') {
			int temp = v.back() * numArr[i + 1];
			v.pop_back();
			v.push_back(temp);
		}
		else if (ops[i] == '/') {
			int temp = v.back() / numArr[i + 1];
			v.pop_back();
			v.push_back(temp);
		}
	}

	// 이제 plus, minus만 남고 v에 숫자 pm에 연산자 있음
	int result = v[0];
	len = pm.length();
	for (int i = 0; i < len; i++) {
		if (pm[i] == '+') {
			result += v[i + 1];
		}
		else {
			result -= v[i + 1];
		}
	}
	//cout << "이것이 result다 : " << result << '\n';

	return result;
}

void rec(int add, int sub, int mul, int div, int k, string s) {

	if (k == n) {
		// 계산할 부분
		int result = calc(s);
		maxNum = max(maxNum, result);
		minNum = min(minNum, result);
	}

	//백트래킹 이용, s에 연산자 순서대로 저장
	if (add > 0) {
		s += "+";
		rec(add - 1, sub, mul, div, k + 1, s);
		s.pop_back();
	}
	if (sub > 0) {
		s += "-";
		rec(add, sub - 1, mul, div, k + 1, s);
		s.pop_back();
	}
	if (mul > 0) {
		s += "*";
		rec(add, sub, mul - 1, div, k + 1, s);
		s.pop_back();
	}
	if (div > 0) {
		s += "/";
		rec(add, sub, mul, div - 1, k + 1, s);
		s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numArr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	string oper = "";
	rec(op[0], op[1], op[2], op[3], 1, oper);

	cout << maxNum << '\n' << minNum << '\n';


	return 0;
}