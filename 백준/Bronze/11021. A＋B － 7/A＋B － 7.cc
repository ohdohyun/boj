#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	int A, B;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << "Case #" << i+1 << ": " << A + B << '\n';
	}



	return 0;
}


