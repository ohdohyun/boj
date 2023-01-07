#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1182

int N, S;
int result = 0;
int arr[20];

void func(int input, int index) {
	if (index == N) { return; }
	if (input + arr[index] == S) { result++; }

	func(input, index + 1);
	func(input + arr[index], index + 1);


}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	func(0, 0);

	cout << result << '\n';

	return 0;
}