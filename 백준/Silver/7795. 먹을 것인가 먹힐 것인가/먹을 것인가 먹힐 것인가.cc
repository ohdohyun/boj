#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/***** 백준 7795 *****/
	int T;
	cin >> T;


	for (int k = 0; k < T; k++) {
		int result = 0;
		int numA, numB, temp;
		cin >> numA >> numB;
		vector<int> A;
		vector<int> B;

		for (int i = 0; i < numA; i++) {
			cin >> temp;
			A.push_back(temp);
		}

		for (int i = 0; i < numB; i++) {
			cin >> temp;
			B.push_back(temp);
		}

		sort(A.begin(), A.end(), cmp );
		sort(B.begin(), B.end(), cmp );
		
		for (int i = 0; i < numA; i++) {
			for (int j = 0; j < numB; j++) {
				if (A[i] > B[j]) {
					result += (numB - j);
					break;
				}
			}
		}

		cout << result << '\n';

	}
    
	return 0;
}