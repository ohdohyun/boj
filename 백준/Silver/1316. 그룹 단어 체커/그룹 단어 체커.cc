#include <iostream>

using namespace std;

bool isGroupNum(string s) {		// 그룹넘버인지 체크
	
	int len = s.length();		
	int arr[26] = { 0, };		// 알파벳별로 나왔는지 체크, 안나왔으면 0 한번 나왔으면 1

	arr[s[0] - 'a'] = 1;		// 첫번째 문자 체크

	for (int i = 1; i < len; i++) {
		if (s[i - 1] == s[i]) { continue; }	// 이전 문자와 같으면 다음문자 체크하러감


		if (arr[s[i] - 'a'] == 1) {			// 이미 나온적 있는 문자면 return false
			return false;
		}

		arr[s[i] - 'a'] = 1;
	}

	return true;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);


	int N; cin >> N;
	int count = 0;

	for (int T = 0; T < N; T++) {
		string input;
		cin >> input;

		if (isGroupNum(input)) { count++; }
	}


	cout << count << '\n';

	return 0;
}


