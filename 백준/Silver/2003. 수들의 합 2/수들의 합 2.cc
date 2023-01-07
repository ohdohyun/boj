#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/


int input[10000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, num;
	cin >> n >> num;

	
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	int st = 0, ed = 0;
	int sum = input[st];
	int cnt = 0;
	while (st <= ed && ed < n) {

		//cout << "sum, num = " << sum << ", " << num << ", || st,ed = " << st << ", " << ed << '\n';
		if (sum == num) { 
			cnt++; 
			if (st == ed) { sum += input[++ed]; }
			else { sum -= input[st++]; }
			//cout << "cnt++\n";
			continue;
		}
		else if (sum < num) {
			if (st == ed) { sum += input[++ed]; continue; }
			sum += input[++ed];
			continue;
		}
		else {
			if (st == ed) { sum += input[++ed]; continue; }
			sum -= input[st++];
		}

	}

	cout << cnt << '\n';
	
	return 0;
}