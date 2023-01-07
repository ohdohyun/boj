#include <iostream>
#include <algorithm>
using namespace std;

int input[100];

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	int gcdnum;
	for (int i = 1; i < n; i++) {
		gcdnum = gcd(input[0], input[i]);
		cout << input[0] / gcdnum << '/' << input[i] / gcdnum << '\n';
	}

	
	return 0;
}