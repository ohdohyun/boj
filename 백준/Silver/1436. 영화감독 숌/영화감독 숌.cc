#include <iostream>
#include <string>
using namespace std;

int i, temp, N, flag, cnt;
string str;
int main() {
	cin >> N;

	while (++i) {
		temp = i, flag = 0;
		while (temp) {
			if (temp % 1000 == 666) {
				flag = 1;
			}
			temp /= 10;
		}
		if (flag) {
			cnt++;
			if (cnt == N) {
				break;
			}
		}
	}
	cout << i << endl;

	return 0;
}
