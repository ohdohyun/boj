#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int money = 1000;
	int count = 0;
	int input;
	cin >> input;
	money -= input;


	while (money >= 500) {
		money -= 500;
		count++;
	}

	while (money >= 100) {
		money -= 100;
		count++;
	}
	while (money >= 50) {
		money -= 50;
		count++;
	}
	while (money >= 10) {
		money -= 10;
		count++;
	}
	while (money >= 5) {
		money -= 5;
		count++;
	}
	while (money >= 1) {
		money -= 1;
		count++;
	}

	cout << count << '\n';


	return 0;
}
