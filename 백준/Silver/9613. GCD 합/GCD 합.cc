#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/9613

int gcd(int a, int b) {
    int temp;
    if (a < b) { swap(a, b); }

    while (true) {
        if (b == 0) { return 0; }
        //if (b == 1) { return 1; }

        if (a % b == 0) { return b; }
        temp = a;
        a = b;
        b = temp % b;
    }
}

int arr[100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) { cin >> arr[i]; }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(arr[i], arr[j]);
                //cout << gcd(arr[i], arr[j]) << '\n';
            }
        }

        cout << sum << '\n';

    }

    return 0;
}