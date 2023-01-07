#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2607

int arr[26];
int cmp[26];
string standard, input;

bool isSimilar(string b) {

	for (int i = 0; i < b.length(); i++) {
		cmp[b[i] - 'A']++;
	}

	bool Chance = true;
	int count = 0;
	for (int i = 0; i < 26; i++) { 
		int sub = arr[i] - cmp[i];

		//cout << 'A' + i << " : " << arr[i] << ' ' << cmp[i] << '\n';
		if (abs(sub) >= 2) { return false; }
		else if (sub == -1) {								// cmp가 하나 더 많다
			if (Chance) { Chance = false; count--; }
			else if (count == 1) { count = 0; }
			else { return false; }
		}												// cmp가 하나 더 적다
		else if (sub == 1) {
			if (Chance == true) { Chance = false; count++; }
			else if (count == -1) { count = 0; }
			else { return false; }
		}		
		

	}

	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	cin >> standard;
	for (int i = 0; i < standard.length(); i++) {
		arr[standard[i] - 'A']++;
	}

	int count = 0;
	for (int i = 1; i < n; i++) {
		cin >> input;
		if(isSimilar(input)) { count++; }
		for (int i = 0; i < 26; i++) { cmp[i] = 0; }
	}
	cout << count << '\n';


	return 0;
}