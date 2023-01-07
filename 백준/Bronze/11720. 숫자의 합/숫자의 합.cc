#include <iostream>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string input;
	int sum = 0;
	int N;
	cin >> N;

	cin >> input;

	for (int i = 0; i < N; i++) {
		sum += input[i] - '0';
	}

	cout << sum << '\n';


	return 0;
}


