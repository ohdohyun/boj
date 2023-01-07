#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/15650

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int arr[8] = { 1,2,3,4,5,6,7,8 };
	
	int N, M;
	cin >> N >> M;
	vector<int> v(N);

	fill(v.begin(), v.begin() + M, 0);
	fill(v.begin() + M, v.end(), 1);

	do {
		for (int i = 0; i < N; i++) {
			if (v.at(i) == 0) { cout << arr[i] << ' '; }
		}
		cout << '\n';

	} while (next_permutation(v.begin(), v.end()));

	return 0;
}