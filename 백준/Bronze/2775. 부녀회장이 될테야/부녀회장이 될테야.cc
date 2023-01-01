#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	int N, M;
	int num[15][15];
	cin >> T;

	for (int i = 0; i < 15; i++) {
		num[i][0] = 1;		// (i*100 +1)호 주민은 1명으로 동일
		num[0][i] = i + 1;	// 0층의 i호에는 i명이 산다.
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			num[i][j] = num[i - 1][j] + num[i][j - 1];
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << num[N][M-1] << '\n';
	}


	return 0;
}









// ios_base::sync_with_stdio(0); cin.tie(0);