#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10808

int arr[26] = {};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	string str;
	cin>>str;
	
	for(int i=0;i<str.length();i++){
		arr[str[i] - 'a']++;
	}
	
	for(int i=0;i<26;i++){
		cout << arr[i] << ' ';
	}

	return 0;
}