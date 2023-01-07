#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	list<char> L;

	cin >> input;
	
	for (int i = 0; i < input.size(); i++) {
		L.push_back(input.at(i));
	}

	int n;
	cin >> n;
	list<char>::iterator cur = L.end();

	while (n--) {
		char c;
		cin >> c;

		if (c == 'L') {
			if (cur != L.begin()) { cur--; }
		}
		else if (c == 'D') {
			if (cur != L.end()) { cur++; }
		}
		else if (c == 'B') {
			if (cur != L.begin()) { cur = L.erase(--cur); }
		}
		else if (c == 'P') {
			char s;
			cin >> s;
			L.insert(cur, s);
		}

	}
	
	for (list<char>::iterator a = L.begin(); a != L.end(); a++) {
		cout << *a;
	}

	return 0;
}