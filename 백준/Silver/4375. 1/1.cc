#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/4375

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    int k = 0;
    while(cin >> N){
        int ans = 1;
        k = 1;
        
        while(1){
            if(ans % N == 0){
                break;
            }
            else{
                k++;
                ans = ans*10 + 1;
                ans %= N;
            }
        }
        
        cout << k << "\n";
    }
	

	return 0;
}