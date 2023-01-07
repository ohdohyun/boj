#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 1e5;
int arr[MAX];
int head = 0, tail = 0;

void arrPrint() {
	for (int i = head; i < tail; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	cout << "head : " << head << ", tail : " << tail << '\n';
}

bool isEmpty() {
	if ((head - tail) == 0) {
		return 1;
	}
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input == "push") {
			cin >> arr[tail];
			tail++;
		}
		else if (input == "pop") {

			if (isEmpty()) { cout << -1 << '\n'; }
			else {
				cout << arr[head] << '\n';
				head++;
			}
		}
		else if (input == "size") {
			cout << tail - head << '\n';
		}
		else if (input == "empty") {
			cout << isEmpty() << '\n';
		}
		else if (input == "front") {
			if (isEmpty()) { cout << -1 << '\n'; }
			else { cout << arr[head] << '\n'; }
		}
		else if (input == "back") {
			if (isEmpty()) { cout << -1 << '\n'; }
			else { cout << arr[tail - 1] << '\n'; }
		}
	}


	return 0;
}