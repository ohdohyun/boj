#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/1969

string answer;
int n, length, sum;
vector <string> DNA;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> length;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        DNA.push_back(s);
    }
    for (int i = 0; i < length; i++) {
        int alphaCnt[26] = { 0 };
        int big = 0;
        char maxAlpha;
        for (int j = 0; j < n; j++) {
            alphaCnt[DNA[j][i] - 'A']++;
            big = max(big, alphaCnt[DNA[j][i] - 'A']);
        }
        for (int k = 0; k < 26; k++) {
            if (alphaCnt[k] == big) {
                answer += k + 'A';
                maxAlpha = k + 'A';
                break;
            }
        }
        for (int k = 0; k < 26; k++) {
            if (k + 'A' != maxAlpha) sum += alphaCnt[k];
        }
    }
    cout << answer << '\n' << sum << '\n';


	return 0;
}