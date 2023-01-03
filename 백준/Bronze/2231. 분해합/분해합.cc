#include<iostream>
#include <cmath>
using namespace std;


int main() {

	int N, min = 1000000;
	cin >> N;

	int result = N, count = 0, sum = 0;


	while (result) {
		result /= 10;
		count++; //자릿수
	}

	result = N;

	for (int i = 0; i < 9 * count; i++) {	//9*자릿수만큼 반복
		
		result = N - i - 1;
		sum = result;
		for (int j = 0; j < count; j++) {
			sum += result % 10;
			result /= 10;


		}
		
		if (sum == N && min >= (N - i - 1)) {
			min = N - i - 1;
		}

	}

	if (min == 1000000) {
		cout << 0 << endl;
	}
	else {
		cout << min << endl;
	}

	return 0;

}
