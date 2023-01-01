#include<iostream>

using namespace std;

bool a[1000001] = { 0,1 };

int main() {
	int i, j, m, n;
	cin >> m >> n;

	for (i = 2; i <= n; i++) {
		for (j = 2; i * j <= n; j++) {
			a[i * j] = 1;
		}
	}
	for (i = m; i <= n; i++) {
		if (!a[i]) {
			printf("%d\n", i);
		}
	}

}
