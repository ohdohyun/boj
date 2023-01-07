#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2309

int arr[9];

bool isAnswer(int a, int b) {
	int sum = 0;
	for(int i=0;i<9;i++){
		if (i == a || i == b) { continue; }
		sum += arr[i];
	}
	if (sum == 100) {
		for (int i = 0; i < 9; i++) {
			if (i == a || i == b) { continue; }
			cout << arr[i] << '\n';
		}
		return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) { cin >> arr[i]; }
	sort(arr, arr + 9);
	
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (isAnswer(i, j)) { return 0; }
		}
	}




	return 0;
}