#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector < pair<pair<int, int>, int>> v;

	for (int i = 0; i < n; i++) {
		int backnumber, rank1, rank2, rank3;
		cin >> backnumber >> rank1 >> rank2 >> rank3;

		v.push_back({ {rank1 * rank2 * rank3,rank1 + rank2 + rank3}, backnumber });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++) {
		cout << v.at(i).second << ' ';		
	}

}