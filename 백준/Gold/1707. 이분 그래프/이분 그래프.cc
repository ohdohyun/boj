#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define M 20001
int visited[M];		//방문한 노드들 표시 0: 미방문, 1: red, 2: blue
vector<int> ed[M];

int v, e;

void clear() {
	for (int i = 0; i <= v; i++) {
		visited[i] = 0;
		ed[i].clear();
	}
	
}

bool bfs(int start) {
	visited[start] = 1;			// 시작 red로 방문
	queue <int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int color = visited[cur];		//현재 노드의 색깔 저장

		for (int i = 0; i < ed[cur].size(); i++) {
			int nv = ed[cur][i];
			//cout << "입장 전 ---  cur: " << cur << ", color: " << color << ", nv: " << nv << ", visited[nv]: " << visited[nv] << '\n';
			if (visited[nv] == 0) { 
				visited[nv] = color == 1 ? 2 : 1; 
				q.push(nv);
				//cout << "push ---  cur: " << cur << ", color: " << color << ", nv: " << nv << ", visited[nv]: " << visited[nv] << '\n';
			}
			else if (visited[nv] == color) { return false; 
			//cout << "false ---  cur: " << cur << ", color: " << color << ", nv: " << nv << ", visited[nv]: " << visited[nv] << '\n';
			}
			else if (visited[nv] != color) { continue; }
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	while (T-- != 0) {
		
		cin >> v >> e;
		clear();
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			ed[a].push_back(b);
			ed[b].push_back(a);
		}
		bool result = true;
		for (int i = 1; i <= v; i++) {
			if (visited[i] != 0) { continue; }		
			result = bfs(i);						// 현재위치에서 시작한 노드가 이분탐색인지 저장
			if (result == false) { break; }
		}
		if (result == false) { cout << "NO\n"; }
		else { cout << "YES\n"; }
	}
	
	return 0;
}