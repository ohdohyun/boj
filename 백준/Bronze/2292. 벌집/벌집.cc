#include<iostream>

using namespace std;

int main() {
	
	int count, input, sum = 1;
	
	cin >> input;

	for (count = 1; input > sum; count++) {

		sum += 6 * count;

	}

	cout << count << endl;



	return 0;
}
