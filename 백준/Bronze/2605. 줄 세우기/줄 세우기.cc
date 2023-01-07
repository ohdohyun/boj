#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2605

int arr[101];

void func(int index,int input) {
	for (int i = 0; i < input; i++) {
		arr[index - i] = arr[index - i - 1];
	}
	arr[index - input] = index;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		func(i, input);
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}