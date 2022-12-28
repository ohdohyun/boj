#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/11000


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> start_time, end_time;

	int cnt = 0;
	while (n--) {
		int start, end;
		cin >> start >> end;
		start_time.push(start);
		end_time.push(end);
	}
	
	//cout << "중간점검\n";

	int result = 0;
	while (!start_time.empty()) {
		// start_time.back 이 더 작으면 cnt++
		// cout << start_time.top() << ", " << end_time.top() << '\n';
		if (start_time.top() < end_time.top()) {
			cnt++;
			start_time.pop();
			result = max(result, cnt);
		}
		else if (start_time.top() == end_time.top()) {
			start_time.pop();
			end_time.pop();
		}
		else {
			cnt--;
			end_time.pop();
		}
	}

	cout << result << '\n';

	return 0;
}