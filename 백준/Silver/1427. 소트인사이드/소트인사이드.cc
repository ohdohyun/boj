#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, input;
	vector<int> v;

	cin >> N;
	while (true) {
		if (N == 0) { break; }
		input = N % 10;
		N /= 10;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = v.size()-1; i>=0; i--) {
		cout << v[i];
	}

	return 0;
}