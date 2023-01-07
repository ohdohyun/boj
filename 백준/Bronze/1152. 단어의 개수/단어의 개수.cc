#include <iostream>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string input;
	getline(cin, input);
	int len = input.length();

	int count = 0;
	int index = -1;


	for (int i = 0; i < len; i++) {
		if (input[i] != ' ') {
			count = 1;
			index = i;
			break;
		}		
	}

	for (int i = index + 1; i < len; i++) {
		if (input[i - 1] == ' ' && input[i] != ' ') {
			count++;
		}
	}

	
	cout << count << '\n';

	return 0;
}


