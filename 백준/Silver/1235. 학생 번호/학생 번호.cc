#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/


string student[1000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> student[i];
	}

	int k = 1;
	int len = student[0].length();
	//cout << len << '\n';

	while (k <= 100) {
		unordered_set<string> s;
		int check = 0;
		for (int i = 0; i < n; i++) {
			// len - k 부터 end까지 문자열을 set에 저장
			// 이미 있으면 k++, continue
			if (s.find(student[i].substr(len - k)) != s.end()) {
				// 이미 있다면
				check = 1;
				break;
			}
			else {
				// 없다면
				s.insert(student[i].substr(len - k));
			}
		}
		if (check) { k++; continue; }	// 구별이 불가능하다면
		else { cout << k << '\n'; break; }
	}



	return 0;
}