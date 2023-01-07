#include <iostream>
#include <queue>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/18258

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	queue <int> q;
	int n, num;
	cin >> n;
	while (n--) {
		string input;
		cin >> input;
		if (input == "push") {
			cin >> num;
			q.push(num);
		}
		else if (input == "pop") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front() << '\n';
			q.pop();
		}
		else if (input == "size"){
			cout << q.size() << '\n';
		}
		else if (input == "empty") {
			cout << q.empty() << '\n';
		}
		else if (input == "front") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front() << '\n';
		}
		else if (input == "back") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.back() << '\n';
		}
	}
    
	return 0;
}