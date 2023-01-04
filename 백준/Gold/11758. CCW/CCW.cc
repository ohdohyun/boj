#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	double ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	double dx = bx - ax;
	double dy = by - ay;

	if (dx == 0) {		// 만약 수직이라면
		if (dy > 0) {	// 위로 수직
			if (cx == ax) { cout << 0 << '\n'; return 0; }
			else if (cx < ax) { cout << 1 << '\n'; return 0; }
			else { cout << -1 << '\n'; return 0; }
		}
		else {			// 아래로 수직
			if (cx == ax) { cout << 0 << '\n'; return 0; }
			else if (cx < ax) { cout << -1 << '\n'; return 0; }
			else { cout << 1 << '\n'; return 0; }
		}
	}

	int ans = dy * cx + by * dx - dy * bx - cy * dx;

	if (ans == 0) { cout << 0 << '\n'; }
	else if (dx > 0) {
		if (ans > 0) { cout << -1 << '\n'; }
		else { cout << 1 << '\n'; }
	}
	else {
		if (ans < 0) { cout << 1 << '\n'; }
		else { cout << -1 << '\n'; }
	}


	return 0;
}