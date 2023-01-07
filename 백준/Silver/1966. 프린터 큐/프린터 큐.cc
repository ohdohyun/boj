#include <iostream>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/1966

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	int T;
	cin >> T;
	while (T--) {
		queue<pair<int, int>> q;
		int importance[10] = {};
		int n, find;

		cin >> n >> find;

		for (int i = 0; i < n; i++) {					// 입력, 찾아야하는 숫자에 input,1로 큐에 푸쉬
			int input;
			cin >> input;
			importance[input]++;						// 중요도별로 몇개인지 importance[중요도] 에 갯수 저장
			if (i == find) { q.push({ input, 1 }); }
			else { q.push({ input,0 }); }
		}

		int count = 1;
		int index = 9;
		while (1) {
			while (!importance[index]) {				// 중요도 높은 숫자가 나올때까지 
				index--;
			}
			//cout << "현재상황 index : " << index << ", q.front : " << q.front().first << ' ' << q.front().second << '\t';


			if (q.front().second == 1 && q.front().first == index) { break; }			// 찾는 숫자면 break;
			else if (q.front().first != index) {										// 중요도 높은숫자가 아니면 큐 맨뒤로
				//cout << "pass \n";
				pair<int, int> cur = q.front();
				q.pop();
				q.push(cur);
			}
			else if (q.front().first == index) {										// 중요도 높은 숫자면 pop
				//cout << "print \n";
				q.pop();
				count++;
				importance[index]--;
			}
		}

		cout << count << '\n';

	}
	

	return 0;
}