#include <iostream>

using namespace std;

int pizza(int num) {
	int a, b, result = 0;
	
	if (num == 1) { return 0; }
	else if (num % 2 == 0) {
		a = num / 2;
		result += (num/2) * (num/2);
		return result + pizza(a) * 2;
	}
	else {
		result += (num / 2) * (num / 2 + 1);
		a = num / 2;
		b = num / 2 + 1;
		return result + pizza(a) + pizza(b);
	}
	
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/***** 백준 14606 *****/
	int N;
	cin >> N;

	cout << pizza(N);
	



	return 0;
}