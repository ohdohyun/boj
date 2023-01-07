#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int result[1000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	
	stack<int> s;
	for (int i = 0; i < n; i++) {
		s.push(i);
		while (!s.empty() && arr[s.top()] < arr[i + 1]) {
			result[s.top()] = arr[i + 1];
			s.pop();
		}
	}

	while (!s.empty()) {
		result[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) { cout << result[i] << ' '; }

	return 0;
}