#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1759

char alphabet[15];
char answer[15];
int L, C;

void func(int index, int from, int to) {

	if (index == L) {

		int aeiou = 0;
		int abcd = 0;
		for (int i = 0; i < L; i++) {
			if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u') { aeiou++; }
			else { abcd++; }
		}

		if (aeiou < 1 || abcd < 2) { return; }
		for (int i = 0; i < L; i++) { cout << answer[i]; }
		cout << '\n';
		return;
	}

	for (int i = from; i < to; i++) {
		answer[index] = alphabet[i];
		func(index + 1, i + 1, to + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> L >> C;

	for (int i = 0; i < C; i++) { cin >> alphabet[i]; }
	sort(alphabet, alphabet + C);
	//for (int i = 0; i < C; i++) { cout << alphabet[i] << ' '; }
	func(0, 0, C - L + 1);

	return 0;
}