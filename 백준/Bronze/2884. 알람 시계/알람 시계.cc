#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int H, M;

	cin >> H >> M;

	if (M < 45) {
		H--;
		M += 15;
	}
	else {
		M -= 45;
	}

	if (H < 0) {
		H += 24;
	}
	cout << H << ' ' << M;
	
	

	return 0;
}


