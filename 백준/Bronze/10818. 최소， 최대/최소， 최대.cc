#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, input;
	cin >> N;
	int min=1000001, max=-1000001;

	for (int i = 0; i < N; i++) {

		cin >> input;
		if (input > max) {
			max = input;
		}
		if (input < min) {
			min = input;
		}

	}

	cout << min << ' ' << max << '\n';




	return 0;
}


