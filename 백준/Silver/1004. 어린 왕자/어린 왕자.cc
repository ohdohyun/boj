#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/1004

long long n, m;
vector<int> v;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--) {
		int stx, sty, edx, edy;

		cin >> stx >> sty >> edx >> edy;
		int n;
		cin >> n;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int px, py, pd;
			cin >> px >> py >> pd;
			pd =pd * pd;
			int stDistance = (stx - px) * (stx - px) + (sty - py) * (sty - py);
			int edDistance = (edx - px) * (edx - px) + (edy - py) * (edy - py);

			if (stDistance < pd && edDistance < pd) { continue; }
			else if (stDistance < pd || edDistance < pd) { cnt++; }
			
		}

		cout << cnt << '\n';
	}
	
	return 0;
}