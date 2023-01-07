#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/11656
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string str;
	cin >> str;

	vector<string> v;

	for (int i = 0; i < str.length(); i++) {
		v.push_back(str.substr(i, str.length()));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << '\n';
	}


	return 0;
}