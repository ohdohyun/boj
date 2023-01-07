#include <iostream>
#include <algorithm>

using namespace std;
// https://www.acmicpc.net/problem/1644

#define M 4000000
int arr[M];

int nextPrime(int a) {
	a++;
	while (a < M && arr[a] == 1) { a++; }
	if (a >= M) { return M + 1; }
	return a;

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 2; i < 2000; i++) {
		for (int j = i; i * j <= 4000000; j++) {
			arr[i * j] = 1;
		}
	}

	int n; cin >> n;

	int st = 2, ed = 2;
	int cnt = 0;
	int sum = 2;
	while (ed <= n) {

		if (sum == n) { cnt++; ed = nextPrime(ed); sum += ed; }
		else if (sum < n) { ed = nextPrime(ed); sum += ed; }
		else if (sum > n) { sum -= st; st = nextPrime(st);  }
		
		//cout << "sum : " << sum << ", st : " << st << ", ed : " << ed << '\n';
	}

	cout << cnt << '\n';

	return 0;
}