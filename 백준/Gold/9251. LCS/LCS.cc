#include <iostream>
#include <algorithm>

using namespace std;

int DP[1002][1002];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    /***** 백준 9251 *****/

    string A, B;
    cin >> A >> B;
    int lenA = A.length();
    int lenB = B.length();

    for (int i = 1; i <= lenB; i++) {
        for (int j = 1; j <= lenA; j++) {
            if (B[i - 1] == A[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }

        
    }

    cout << DP[lenB][lenA];
    


    return 0;
}