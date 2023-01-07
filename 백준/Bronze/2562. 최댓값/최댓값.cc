#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int input, position = 0;
	
	int max = 0;;

	for (int i = 0; i < 9; i++) {

		cin >> input;
		if (input > max) {
			max = input;
			position = i + 1; 
		}
		

	}

	cout << max << ' ' << position << '\n';




	return 0;
}


