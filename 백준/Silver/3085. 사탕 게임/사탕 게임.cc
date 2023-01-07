#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/3085

char map[50][50];
int n, ans = 0;
int dx[2] = { 0,1 }, dy[2] = { 1,0 };

void check() {
	// 바꾼 후 최대 몇개인지 체크할 함수, cnt에 임시맥스 저장, ans에 최종저장
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) {
				cnt++;
			}
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}

	for (int j = 0; j < n; j++) {
		cnt = 1;
		for (int i = 1; i < n; i++) {
			if (map[i][j] == map[i-1][j]) {
				cnt++;
			}
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	
}

void change(int x, int y) {
	// 두 자리를 바꿀 함수, 현재 좌표를 받아서 오른쪽과 바꾸고 아래와 바꿈. 전부 범위 안 expt 없음

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == n || ny == n) { continue; }
		swap(map[x][y], map[nx][ny]);
		check();
		swap(map[x][y], map[nx][ny]);		// 원래대로 복구
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	check();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			change(i, j);
			if (ans == n) { cout << ans << '\n'; return 0; }
		}
	}

	cout << ans << '\n';


	return 0;
}