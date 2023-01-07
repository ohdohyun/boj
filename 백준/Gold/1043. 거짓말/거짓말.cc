#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/1043

int map[51][51];		//[party][people]
int partyVisited[51];
int peopleVisited[51];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n >> m;

	int num_truth;
	cin >> num_truth;

	for(int i=0;i<num_truth;i++){		// 진실을 아는 사람 
		int input;
		cin >> input;
		peopleVisited[input] = 1;
		q.push(input);
	}

	for (int i = 1; i <= m; i++) {		// 파티별 인원 입력
		int num_party;
		cin >> num_party;
		for (int j = 0; j < num_party; j++) {	// i번째 파티에 누가왔는지
			int input;
			cin >> input;
			map[i][input] = 1;
		}
	}

	while (!q.empty()) {

		int cur = q.front(); q.pop();

		for (int i = 1; i <= m; i++) {
			if (map[i][cur] == 1 && partyVisited[i] == 0) {			// cur번째 사람이 i번째 파티에 참석했는지
				for (int j = 1; j <= n; j++) {
					if (map[i][j] == 1 && peopleVisited[j] == 0) {	// 그 파티에 참석한 사람중 방문 안했으면 q에 푸쉬
						q.push(j);
						peopleVisited[j] = 1;
					}
				}
				partyVisited[i] = 1;								// 파티 방문처리
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (partyVisited[i] == 0) {
			cnt++;
		}
	}

	cout << cnt << '\n';


	return 0;
}