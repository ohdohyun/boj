#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2004

int func2(int n){
	int res=0;
	while(n>=2){
		res+= n/2;
		n/=2;
	}
	return res;
}

int func5(int n){
	int res=0;
	while(n>=5){
		res+= n/5;
		n/=5;
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int m, n;
	
	cin>> m >> n;
	
	int x2 = func2(m);
	int x5 = func5(m);
	
	int y2 = func2(n);
	int y5 = func5(n);
	
	int z2 = func2(m-n);
	int z5 = func5(m-n);
	
	int a = x2-y2-z2;
	int b = x5-y5-z5;
	
	cout << min(a,b) << '\n';
	
	
	return 0;
}