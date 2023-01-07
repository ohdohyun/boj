#include <iostream>

using namespace std;

int N, cnt = 0;
int line1[40] = { 0, };
int line2[40] = { 0, };
int line3[40] = { 0, };


void Queen(int cur) {

	if (cur == N) { cnt++; return; }


	for (int i = 0; i < N; i++) {
		if (line1[i] || line2[cur - i + N - 1] || line3[cur + i])
			continue;

		line1[i] = 1;
		line2[cur - i + N - 1] = 1;
		line3[i + cur] = 1;
		Queen(1 + cur);
		line1[i] = 0;
		line2[cur - i + N - 1] = 0;
		line3[i + cur] = 0;

	}


}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	Queen(0);

	cout << cnt;

	return 0;
}


