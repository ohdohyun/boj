#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    /***** 백준 11653 *****/

    int divideNum = 2;
    int N;
    cin >> N;

    while (N != 1) {
        while (1) {
            if (N % divideNum == 0) {
                N /= divideNum;
                cout << divideNum << '\n';
            }
            else { divideNum++; break;  }
        }
    }


    return 0;
}

