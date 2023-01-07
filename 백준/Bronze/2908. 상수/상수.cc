#include <iostream>
#include <algorithm>

using namespace std;

int sangsu(int n) {

	int result = 0;

	result = (n % 10) * 100;
	n /= 10;
	result += (n % 10) * 10;
	n /= 10;
	result += n;

	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	cout << max(sangsu(a), sangsu(b)) << '\n';



	return 0;
}


