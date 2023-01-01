#include<iostream>

using namespace std;

int main() {
	
	int input, i;
	cin >> input;

	int sum = 0;
	int x, y, res;


	for (i = 0; input > sum + i; i++) {	sum += i; }
	res = input - sum;

	if (i % 2 == 1) {
		x = i + 1 - res;
		y = i + 1 - x;
	}
	else {
		y = i + 1 - res;
		x = i + 1 - y;
	}

	cout << x << '/' << y << endl;


	return 0;
}
