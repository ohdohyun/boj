#include<iostream>
#include<cmath>

using namespace std;

int fibonacci(int n);

int main() {
	int n;
	cin >> n;
	
	cout << fibonacci(n) << endl;

	return 0;

}

int fibonacci(int n) {
	if ( n == 0 ) {
		return 0;
	}
	else if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}


}