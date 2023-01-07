#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/2293


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
  cin >> n;

  vector<int> v;
  for(int i=0;i<n;i++){
    int input;
    cin>>input;
    v.push_back(input);
  }

  sort(v.begin(),v.end());

  int m = 0;
  for(int i=0;i<n;i++){
    m = max(m, v.at(n-i-1)*(i+1) );
  }

  cout << m <<'\n';
  
	return 0;
}