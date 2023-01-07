#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2845

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
       int a, b;
       cin >> a>> b;

       for(int i=0;i<5;i++){
       int n;
cin >> n;
cout << n - a*b << ' ';
}

	return 0;
}