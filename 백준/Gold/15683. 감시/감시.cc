#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/15683

#define M 8
int map[M][M];
int temp[M][M];
int result = 70;
int row, col;
int option[8] = {};			///// 위 1 아래 2 오른쪽 3 왼쪽 4 를 넣어두면 해당 방향으로 감시표시 남겨줌
vector <pair<int, int>> position;			///// cctv들의 위치 저장

//temp 출력
void printMap() {
	cout << '\n';
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << temp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

//사각지대 카운트
int countZero() {
	int result = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (temp[i][j] == 0) {
				result++;
			}
		}
	}
	return result;
}

// temp 초기화
void mapToTemp() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

//단방향 색칠
void paint(int index, int pos) {
	int x = position[pos].first;
	int y = position[pos].second;

	//cout << x << ' ' << y << '\n';
	if (index == 0) { return; }
	else if (index == 1) {	// 위쪽
		while (1) {
			if (x < 0 || map[x][y] == 6) { break; }
			temp[x--][y] = 1;
		}
	}
	else if (index == 2) {
		while (1) {
			if (x >= row || map[x][y] == 6) { break; }
			temp[x++][y] = 1;
		}
	}
	else if (index == 3) {
		while (1) {
			if (y >= col || map[x][y] == 6) { break; }
			temp[x][y++] = 1;
		}
	}
	else if (index == 4) {
		while (1) {
			if (y < 0 || map[x][y] == 6) { break; }
			temp[x][y--] = 1;
		}
	}


}

//cctv 종류별 색칠
void cctvpaint(int shape, int pos) {
	int x = position[pos].first;
	int y = position[pos].second;
	//cout << "cctvpaint : " << x << ", " << y << "모양, 방향 : " << map[x][y] << ' ' << shape << '\n';

	switch (map[x][y]) {
	case 1:
		if (shape == 1) { paint(1, pos); }						// 위 색칠
		else if (shape == 2) { paint(2, pos); }					// 아래 색칠
		else if (shape == 3) { paint(3, pos); }					// 오른쪽 색칠
		else if (shape == 4) { paint(4, pos); }					// 왼쪽 색칠
		break;
	case 2:
		if (shape == 1) { paint(1, pos); paint(2, pos); }		// 위 아래 색칠
		else if (shape == 2) { paint(3, pos); paint(4, pos); }	// 좌 우 색칠
		break;
	case 3:
		if (shape == 1) { paint(1, pos); paint(3, pos); }
		else if (shape == 2) { paint(3, pos); paint(2,pos); }
		else if (shape == 3) { paint(2, pos); paint(4, pos); }
		else if (shape == 4) { paint(4, pos); paint(1, pos); }
		break;
	case 4:
		if (shape == 1) { paint(2, pos); paint(3, pos); paint(4, pos); }
		else if (shape == 2) { paint(1, pos); paint(3, pos); paint(4, pos); }
		else if (shape == 3) { paint(1, pos); paint(2, pos); paint(4, pos); }
		else if (shape == 4) { paint(1, pos); paint(2, pos); paint(3, pos); }
		break;
	case 5:
		paint(1, pos); paint(2, pos); paint(3, pos); paint(4, pos);
	}
}

int numberOfCCTV;
void recursion(int num) {


	if (num == numberOfCCTV) {
		
		for (int i = 0; i < numberOfCCTV; i++) {
			cctvpaint(option[i], i);
			result = min(result, countZero());
		}
		//printMap();
		mapToTemp();
		return;
	}
	//cout << "현재 num : " << num << ", numofcctv : " << numberOfCCTV << ", pos : " << position[num].first << ", " << position[num].second << "  option : " << option[num] << '\n';;
	int x = position[num].first;
	int y = position[num].second;

	switch (map[x][y]) {
	case 1:
		for (int i = 1; i <= 4; i++) {
			option[num] = i;
			num++;
			//cout << "recursion num : " << num << '\n';
			recursion(num);
			num--;
		}
		break;
	case 2:
		for (int i = 1; i <= 2; i++) {
			option[num] = i;
			num++;
			recursion(num);
			num--;
		}
		break;
	case 3:
	case 4:
		for (int i = 1; i <= 4; i++) {
			option[num] = i;
			num++;
			recursion(num);
			num--;
		}
		break;
	
	case 5:
		option[num] = 1;
		num++;
		recursion(num);
		num--;
		break;
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> row >> col;

	int cctvCount = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				position.push_back({ i,j });
				cctvCount++;
			}
		}
	}
	numberOfCCTV = cctvCount;
	
	mapToTemp();
	if (cctvCount == 0) {
		cout << countZero() << '\n';
	}
	else {
		recursion(0);
		cout << result;
	}
	return 0;
}