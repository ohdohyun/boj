#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, X;
	cin >> N >> X;
	
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input < X) {
			cout << input << ' ';
		}
	}



	return 0;
}


