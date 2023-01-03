#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int mode[8001] = { 0, };

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, input, sum = 0;

	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		mode[input+4000]++;
		v.push_back(input);
		sum += input;

	}

	sort(v.begin(), v.end());

	sum = round((double)sum/N);		///// 산술 평균 /////

	int middle = v[N / 2];			///// 중앙값 /////

	int max = 0;					///// 최빈값 /////
	for (int i = 1; i < 8001; i++) {
		if (mode[i] > mode[max]) {
			max = i;
		}
	}
	for (int i = max+1; i < 8001; i++) {
		if (mode[i] == mode[max]) {
			max = i;
			break;
		}
	}

	int range;						///// 범위 /////
	if (N > 1) { range = v[N - 1] - v[0]; }
	else { range = 0; }	

	cout << sum << '\n' << middle << '\n' << max-4000 << '\n' << range;

	return 0;
}