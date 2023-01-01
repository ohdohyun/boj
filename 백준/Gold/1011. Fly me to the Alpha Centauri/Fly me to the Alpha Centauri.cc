#include<iostream> 

using namespace std; 

int main() {

	long long int x, y, sum;
	int count;
	int t; //반복횟수
	cin >> t;

	for (int j = 0; j < t; j++) {
		cin >> x >> y;
		sum = 0;
		count = 0;
		for (int i = 1; ; i++) {
			
			sum += i;
			count++;
			if (sum >= y - x) {
				break;
			}

			sum += i;
			count++;
			if (sum >= y - x) {
				break;
			}
		}
		 
		cout << count << endl;
	}

	
	return 0;
}

