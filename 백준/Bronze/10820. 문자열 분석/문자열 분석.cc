#include <iostream>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/1935


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;

	while (getline(cin,str)) {
		int small = 0, big = 0, num = 0, space = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				small++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				big++;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				num++;
			}
			else if (str[i] == ' ') {
				space++;
			}
		}
		cout << small << ' ' << big << ' ' << num << ' ' << space << '\n';
	}



	return 0;
}