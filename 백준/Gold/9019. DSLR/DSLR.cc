#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/2164

pair<int, char> path[10000];
bool visited[10000];
char ddir[4] = { 'D', 'S', 'L', 'R' };
int inputa, inputb;

int Dfunc(int input) {
	return input * 2 % 10000;
}
int Sfunc(int input) {
	if (input == 0) { return 9999; }
	return input - 1;
}
int Lfunc(int input) {
	int d1, d2, d3, d4;
	d4 = input % 10;
	input /= 10;
	d3 = input % 10;
	input /= 10;
	d2 = input % 10;
	input /= 10;
	d1 = input % 10;
	input /= 10;

	int result = d1 + d4 * 10 + d3 * 100 + d2 * 1000;
	return result;
}
int Rfunc(int input) {
	int d1, d2, d3, d4;
	d4 = input % 10;
	input /= 10;
	d3 = input % 10;
	input /= 10;
	d2 = input % 10;
	input /= 10;
	d1 = input % 10;
	input /= 10;

	int result = d3 + d2 * 10 + d1 * 100 + d4 * 1000;
	return result;
}
void visitedClear() {
	for (int i = 0; i < 10000; i++) {
		visited[i] = 0;
	}
}

void bfs(int a) {
	queue<int> q;
	q.push(a);
	visited[a] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int nn[4] = { Dfunc(cur), Sfunc(cur), Lfunc(cur), Rfunc(cur) };

		for (int i = 0; i < 4; i++) {
			if (visited[nn[i]] == 1) { continue; }
			//cout << "현재상황 : " << nn[i] << ", " << cur << '\n';
			path[nn[i]] = { cur, ddir[i] };
			visited[nn[i]] = 1;
			q.push(nn[i]);
			if (nn[i] == inputb) { 
				q = queue<int>();
				return; 
			}
		}
	}
}

void print(int b) {
	stack <char> s;
	int cur = b;
	while (1) {
		if (inputa != b) {
			s.push(path[b].second);
			b = path[b].first;
		}
		else if (inputa == b) { break; }
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		cin >> inputa >> inputb;
		bfs(inputa);
		print(inputb);
		visitedClear();
	}
	//cout << Dfunc(num) << ' ' << Sfunc(num) << ' ' << Lfunc(num) << ' ' << Rfunc(num) << '\n';

	return 0;
}