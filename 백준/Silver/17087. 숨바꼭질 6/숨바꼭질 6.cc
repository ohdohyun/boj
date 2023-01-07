#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/9613

int gcd(int a, int b) {
    int temp;
    if (a < b) { swap(a, b); }

    while (true) {
        if (b == 0) { return 0; }

        if (a % b == 0) { return b; }
        temp = a;
        a = b;
        b = temp % b;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(abs(S - input));
    }
    
    int D = v.at(0);
    for (int i = 1; i < v.size(); i++) {
        D = gcd(D, v.at(i));
    }

    cout << D << '\n';


    return 0;
}