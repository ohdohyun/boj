#include<iostream> 
#include<cmath>
using namespace std; 

int main() {

	int t, n, count = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		
		cin >> n;
		count++;
		if (n <= 1) {
			count--;
			continue;
		}
		if (n == 2) {
			continue;
		}
		for (int j = 2; j <= sqrt(n); j++) {
			if (n % j == 0) {
				count--;
				break;
			}
		}

	}
	
	cout << count << endl;

	return 0;
}

