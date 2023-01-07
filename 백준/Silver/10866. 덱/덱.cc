#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	deque<int> dq;

	while (T--) {
		string order;
		cin >> order;

		if (order == "push_front") {
			//정수 x를 덱 앞에 넣는다
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (order == "push_back") {
			//정수 x를 덱 뒤에 넣는다
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (order == "pop_front") {
			//덱 가장 앞의 수를 빼고, 출력. 없으면 -1
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else if (order == "pop_back") {
			//덱 가장 뒤의 수를 빼고, 출력. 없으면 -1
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		else if (order == "size") {
			cout << dq.size() << '\n';
		}
		else if (order == "empty") {
			//비어있으면 1 아니면 0
			if (dq.empty()) { cout << 1 << '\n'; }
			else { cout << 0 << '\n'; }
		}
		else if (order == "front") {
			//덱 가장앞의 정수 출력 or -1
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.front() << '\n';
		}
		else if (order == "back") {
			//덱 가장뒤의 정수 출력 or -1
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.back() << '\n';
		}
	}
	
	return 0;
}