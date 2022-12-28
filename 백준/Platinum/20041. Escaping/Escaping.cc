#include <iostream>
#include <algorithm>
using namespace std;

int police[500000][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	int x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> police[i][0] >> police[i][1];
	}

	cin >> x >> y;

	int up = 1, down = 1, right = 1, left = 1;
	for (int i = 0; i < n; i++) {										
		if ((police[i][0] >= x && police[i][1] >= y) ) {				// 도둑보다 오른쪽 위 경찰
			if (police[i][0] - x >= police[i][1] - y) { right = 0; }	//right
			if (police[i][0] - x <= police[i][1] - y) { up = 0; }		//up
		}
		else if (police[i][0] >= x && police[i][1] <= y) {				// 도둑보다 오른쪽 아래 경찰
			if (police[i][0] - x >= y - police[i][1]) { right = 0; }	//right
			if (police[i][0] - x <= y - police[i][1]) { down = 0; }		//down
		}
		else if (police[i][0] <= x && police[i][1] >= y) {				// 도둑보다 왼쪽 위 경찰
			if (x - police[i][0] >= police[i][1] - y) { left = 0; }		//left
			if (x - police[i][0] <= police[i][1] - y) { up = 0; }		//up
		}
		else if (police[i][0] <= x && police[i][1] <= y) {				// 도둑보다 왼쪽 아래 경찰
			if (x - police[i][0] <= y - police[i][1]) { down = 0; }		//down
			if (x - police[i][0] >= y - police[i][1]) { left = 0; }		//left
		}
	}
	
	if ((up + down + right + left) >= 1) {
		cout << "YES" << '\n';
	}
	else{ cout << "NO" << '\n'; }

	return 0;
}