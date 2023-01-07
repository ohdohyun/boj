#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/***** 백준 14247 *****/

	int n, input;
	long long result = 0;
	cin >> n;
	vector<int> tree;

	for (int i = 0; i < n; i++) {		// 처음 나무 길이들을 다 더한다.
		cin >> input;
		result += input;
	}

	for (int i = 0; i < n; i++) {		// 나무가 자라는 길이들을 vector에 입력
		cin >> input;
		tree.push_back(input);
	}

	sort(tree.begin(), tree.end());		// 나무가 자라는 길이들을 오름차순 정렬

	for (int i = 0; i < n; ++i) {
		result += tree[i] * static_cast<long long>(i);			// n일차에 n번째로 늦게자라는 나무를 자란만큼 수확
		//cout << i << ' ' << tree[i] << '\n';
	}									// 1일차는 제외하고 2일차를 i=1로 잡고 진행
	cout << result << '\n';




	return 0;
}