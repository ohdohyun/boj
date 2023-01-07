#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
// https://www.acmicpc.net/problem/19583

int string_to_time(string time) {
	int hour, minute;
	hour = stoi(time.substr(0, 2));
	minute = stoi(time.substr(3, 2));

	return hour * 60 + minute;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s_time, c_time, e_time;
	cin >> s_time >> c_time >> e_time;
	int start = string_to_time(s_time), complete = string_to_time(c_time), end = string_to_time(e_time);
	// cout << start << '\t' << complete << '\t' << end << '\n';

	unordered_set<string> before, after;
	string chat_time, name;
	int cnt = 0;
	while (cin >> chat_time >> name) {
		int chat = string_to_time(chat_time);
		// cout << chat << '\n';
		if (chat <= start) {
			before.insert(name);
		}
		else if (chat >= complete && chat <= end && (before.find(name) != before.end()) ) {
			before.erase(before.find(name));
			cnt++;
		}
	}
	cout << cnt << '\n';


	return 0;
}