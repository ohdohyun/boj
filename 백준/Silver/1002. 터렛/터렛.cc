#include<iostream>
#include<cmath>

using namespace std;

int main() {


	int x1, x2, y1, y2, r1, r2, d;

	int t;

	cin >> t;


	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		// ((r1 + r2) * (r1 + r2))

		//두원이 서로 밖에 있거나 한쪽이 다른쪽을 내부에 포함할 때
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		else if (((r1 + r2) * (r1 + r2)) < d || ((r1 - r2) * (r1 - r2)) > d) {
			cout << 0 << endl;
		}
		else if (((r1 + r2) * (r1 + r2)) == d || ((r1 - r2) * (r1 - r2)) == d) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}

}
