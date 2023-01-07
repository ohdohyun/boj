#include <iostream>
#include <algorithm>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	string input;
	cin >> input;
	int len = input.length();

	int count = 0;
	for (int i = 0; i < len; i++) {

		if (input[i] == 'c' && input[i + 1] == '=') { i++; }
		else if (input[i] == 'c' && input[i + 1] == '-') { i++; }
		else if (input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=') { i += 2; }
		else if (input[i] == 'd' && input[i + 1] == '-') { i++; }
		else if (input[i] == 'l' && input[i + 1] == 'j') { i++; }
		else if (input[i] == 'n' && input[i + 1] == 'j') { i++; }
		else if (input[i] == 's' && input[i + 1] == '=') { i++; }
		else if (input[i] == 'z' && input[i + 1] == '=') { i++; }


		count++;
	}


	cout << count << '\n';

	return 0;
}


