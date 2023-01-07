#include <iostream>
#include <algorithm>

using namespace std;

int map[9][9];
int isClear = 0;

void printMap() {								//맵 출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool check(int x, int y, int k) {				//조건확인
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == k) { return false; }	//가로 확인
		if (map[i][y] == k) { return false; }	//세로 확인
	}

	x /= 3; y /= 3;
	x *= 3; y *= 3;

	for (int i = 0; i < 3; i++) {				//대각 확인
		for (int j = 0; j < 3; j++) {
			if (map[x + i][y + j] == k) {
				return false;
			}
		}
	}

	return true;
}

void sudoku(int position) {						//메인 재귀


	if (position == 81) { printMap(); isClear = 1; }
	if (isClear) { return; }
	

	int x = position / 9;
	int y = position % 9;

	//cout << x << ' ' << y << '\n';

	if (map[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {

			if (check(x, y, i)) {
				map[x][y] = i;
				sudoku(position + 1);
				map[x][y] = 0;
			}
			

		}
	}
	else { sudoku(position + 1); }




	

	
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}

	//cout << '\n';

	sudoku(0);





	return 0;
}


