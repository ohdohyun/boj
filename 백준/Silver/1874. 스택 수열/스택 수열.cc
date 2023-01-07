#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


int arr[100000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	queue<char> q;
	int point = 1;
	int index = 0;

	while (1) {

		if (s.empty()) {
			s.push(point++);
			q.push('+');
		}
		else if (s.top() == arr[index]) {
			index++;
			s.pop();
			q.push('-');
		}
		else if(arr[index] >= point) { s.push(point++); q.push('+'); }
		else {
			point++;
		}

		if (point > n) { break; }

	}

	while (!s.empty()) { 
		if (s.top() == arr[index]) {
			q.push('-'); 
		}
		s.pop();
		index++;
	}

	if (q.size() == 2 * n) {
		while (!q.empty()) {
			cout << q.front() << '\n';
			q.pop();
		}
	}
	else {
		cout << "NO\n";
	}


	return 0;
}