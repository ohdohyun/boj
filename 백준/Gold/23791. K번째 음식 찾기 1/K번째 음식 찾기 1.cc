#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/23791

int kor[100001], eu[100001];
int sum[200002];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {         // 한식부터 입력
        cin >> kor[i];
        sum[i] = kor[i];               // sum배열에 한식 추가
    }
    for (int i = 0; i < n; i++) {
        cin >> eu[i];                  // 양식 입력
        sum[n + i] = eu[i];               // sum배열에 양식 추가
    }
    sort(sum, sum + n * 2);               // 한식 + 양식 전체 맛을 배열에 저장

    /*for (int i = 0; i < n * 2; i++) {
       cout << sum[i] << ' ';
    }*/

    int q;
    cin >> q;

    while (q--) {
        //cout << "####" << '\n';
        int a, b, f;
        cin >> a >> b >> f;

        int tf = sum[f - 1];                  // 전체 음식중에 f번째로 맛있는 음식의 맛을 tf에 저장
        //cout << tf << "/////" <<'\n';

        int ap = lower_bound(kor, kor + n, tf) - kor + 1;
        int bp = lower_bound(eu, eu + n, tf) - eu + 1;
        
        //cout << "#1 ap, bp= " << ap << ", " << bp << '\n';

        if (ap > n) { ap--; }
        if (bp > n) { bp--; }

        if (kor[ap - 1] > tf) { ap--; }         // 무조건 전체에서 f번째보다 작은수로 이동
        if (eu[bp - 1] > tf) { bp--; }

        
        //cout << "#2 ap, bp= " << ap << ", " << bp << '\n';

        if (ap > a) {                           // 한식에서 a번째를 넘겼으면 넘은만큼 b번째 증가
            bp += ap - a;
            ap -= a;
        }
        else if (bp > b) {                      // 양식에서 b번째를 넘었으면 넘은만큼 a번째 증가
            ap += bp - b;
            bp -= b;
        }
        //cout << "#3 ap, bp= " << ap << ", " << bp << '\n';

        if (kor[ap - 1] >= tf) {                // f번째 보다 크거나 같으면 출력
            cout << 1 << ' ' << ap << '\n';
        }
        else if(eu[bp-1] >= tf) {
            cout << 2 << ' ' << bp << '\n';
        }



    }

    return 0;
}