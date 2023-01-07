#include <iostream>
using namespace std;

bool arr[10000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; 	cin >> N;

	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (arr[input] == false) { arr[input] = true; }
		else { cout << input << '\n'; break; }
		
	}



	

	return 0;
}


