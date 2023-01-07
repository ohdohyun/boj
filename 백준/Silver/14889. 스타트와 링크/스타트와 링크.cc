#include <iostream>

using namespace std;

int N, M, minScore = 99999999;		//N은 전체 명수 M은 N/2
int score[21][21] = { 0, };
int teamA = 0, teamB = 0;			//A,B팀의 전체 시너지점수의 합
int isused[21];						//1~20번의 선수들이 팀원으로 선정됐는지

void teamScore(int k, int index) {

	if (k == M) {					//A팀이 N/2명이 되면.

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (isused[i] == 1 && isused[j] == 1) {				//isused[i], [j] 둘다 1이면 A팀이라는 의미
					teamA += score[i][j];
					teamA += score[j][i];
				}
				else if (isused[i] == 0 && isused[j] == 0) {		//isused[i], [j] 둘다 0이면 B팀이라는 의미
					teamB += score[i][j];
					teamB += score[j][i];
				}
			}
		}

		if (teamA >= teamB) {										//A팀의 점수가 더 크면 A-B를 해야 음수가 안나옴
			if (teamA - teamB < minScore) {
				minScore = teamA - teamB;
			}
		}
		else {
			if (teamB - teamA < minScore) {							//B팀의 점수가 더 크면 B-A를 해야 음수가 안나옴
				minScore = teamB - teamA;
			}
		}
		teamA = 0; teamB = 0;
		return;
	}

	for (int i = index; i <= N; i++) {
		if (!isused[i]) {
			isused[i] = 1;		//teamA로 영입
			teamScore(k + 1, i + 1);
			isused[i] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	M = N / 2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> score[i][j];
		}
	}

	isused[1] = 1;				//1번선수를 A팀으로
	teamScore(1, 2);			//1명 뽑은후 재귀진행

	cout << minScore << '\n';


	return 0;
}


