#include <iostream>
#include <algorithm>

using namespace std;

int N, minNum = 987654321, maxNum = -987654321;
int numArr[11];
int op[4];


void rec(int add, int sub, int mul, int div, int k, int result) {

	if (k == N) {
		maxNum = max(maxNum, result);
		minNum = min(minNum, result);
	}

	if (add > 0) {
		rec(add - 1, sub, mul, div, k + 1, result + numArr[k]);
	}
	if (sub > 0) {
		rec(add , sub - 1, mul, div, k + 1, result - numArr[k]);
	}
	if (mul > 0) {
		rec(add , sub, mul - 1, div, k + 1, result * numArr[k]);
	}
	if (div > 0) {
		rec(add , sub, mul, div - 1, k + 1, result / numArr[k]);
	}

}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numArr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	rec(op[0], op[1], op[2], op[3], 1, numArr[0]);

	cout << maxNum << '\n' << minNum << '\n';


	return 0;
}


