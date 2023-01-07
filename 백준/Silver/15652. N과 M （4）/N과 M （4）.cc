#include <iostream>

using namespace std;

int N, M;
int arr[10];
int isused[10];

void nm(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (k==0 || (arr[k-1] <= i) ) {
			arr[k] = i;
			isused[i] = 1;
			nm(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	nm(0);





	return 0;
}


