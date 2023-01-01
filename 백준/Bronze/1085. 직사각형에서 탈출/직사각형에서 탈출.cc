#include<iostream>
#include<cmath>

using namespace std;


int main() {
	
	int x, y, w, h, min;

	cin >> x >> y >> w >> h;
	min = x;

	if (min > w - x) {
		min = w - x;
	}
	if (min > y) {
		min = y;
	}
	if (min > h - y) {
		min = h - y;
	}

	cout << min << endl;
}
