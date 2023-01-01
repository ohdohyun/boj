#include<iostream>

using namespace std;

int main() {
	
	int A, B, C;
	int n = 0;

	cin >> A >> B >> C;
	


	if (B >= C) {
		cout << -1 << endl;
	}
	else {
		cout << A / (C - B) + 1 << endl;
	}



	return 0;
}

