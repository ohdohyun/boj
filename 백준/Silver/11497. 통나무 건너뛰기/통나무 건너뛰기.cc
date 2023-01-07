#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int T;
	cin >> T;


	while (T != 0) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + N);

		int even = arr[1] - arr[0];
		int odd = arr[2] - arr[0];

		for (int i = 3; i < N; i++) {
			if (i % 2 == 0) {
				even = max(even, arr[i] - arr[i - 2]);
			}
			else {
				odd = max(odd, arr[i] - arr[i - 2]);
			}
		}

		cout << max(even, odd) << '\n';

		

		T--;
	}


	return 0;
}