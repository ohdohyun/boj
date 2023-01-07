#include <iostream>
#include <algorithm>

using namespace std;

int input[50];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int minNum = 1000001;
    int maxNum = 1;

    for (int i = 0; i < N; i++) {
        cin >> input[i];
        minNum = min(minNum, input[i]);
        maxNum = max(maxNum, input[i]);
    }

    cout << minNum * maxNum;
    

	return 0;
}
