#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    /***** 백준 10757 *****/


    string a, b;
    cin >> a >> b;

    string rA = a;
    reverse(rA.begin(), rA.end());
    string rB = b;
    reverse(rB.begin(), rB.end());

    string sol;
    int carry = 0;

    int size = max(rA.size(), rB.size());
    for (int i = 0; i < size; i++) {
        int a = (i < rA.size()) ? rA[i] - '0' : 0;
        int b = (i < rB.size()) ? rB[i] - '0' : 0;
        int sum = a + b + carry;
        carry = sum / 10;
        sol.push_back(char(sum % 10 + '0'));
    }
    if (carry)
        sol.push_back(char(carry % 10 + '0'));

    reverse(sol.begin(), sol.end());
    cout << sol;




    return 0;
}

