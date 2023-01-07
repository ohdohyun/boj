#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
// https://www.acmicpc.net/problem/14425

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
    
	unordered_set<string> us;
	while(n--){
		string input;
		cin >> input;
		us.insert(input);
	}

	int cnt = 0;
	while (m--) {
		string input;
		cin >> input;
		if (us.find(input) != us.end()) {
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}