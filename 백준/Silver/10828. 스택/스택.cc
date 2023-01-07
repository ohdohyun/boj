#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10001];
int top = -1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t-- > 0) {
		
		string input;
		cin >> input;
		int num;

		if (input == "push") {	
			cin >> num;
			top++;
			arr[top] = num;
		}
		else if (input == "pop") {
			if (top == -1) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[top] << '\n';
				top--;
			}
		}
		else if (input == "size") {
			cout << top + 1 << '\n';
		}
		else if (input == "empty") {
			if (top == -1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (input == "top") {

			if (top == -1) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[top] << '\n';
			}
		}


	}

	

	

	return 0;
}
