#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	int result = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 2; i <= 100; i++) {
			if (arr[cur][i] == 1 && visited[i] == 0) {
				result++;
				visited[i] = 1;
				q.push(i);
			}
		}

	}

	cout << result << '\n';

	return 0;
}