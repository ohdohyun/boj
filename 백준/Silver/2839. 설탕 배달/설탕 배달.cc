#include<iostream>

using namespace std;

int main() {
	
	int n,count = 0;
	cin >> n;

	if ((n == 1) || (n == 2) || (n == 4) || (n == 7)) {
		cout << -1 << endl;
	}
	else {

		switch (n % 5) {
		case 0:
			cout << n / 5 << endl;
			break;
		case 1:
		case 3:
			cout << n / 5 + 1 << endl;
			break;
		case 2:
		case 4:
			cout << n / 5 + 2 << endl;
			break;
		}
	}





	return 0;
}

