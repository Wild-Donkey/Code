#include<iostream>
#include<cstdio>
using namespace std;
int m, n, ans, ans_2, ans_3, cnt, cnt_2, cnt_3, q[1000006];
int main()
{
    while (cin >> n >> m) {
        cnt = 1;
        q[1] = n;
        cnt_2 = 1;
        cnt_3 = 1;
        while (cnt < m) {
            ans_2 = q[cnt_2] * 2 + 1;
            ans_3 = q[cnt_3] * 3 + 1;
            if (ans_2 >= ans_3) {
                ans = ans_3;
                cnt_3++;
            }
            else {
                ans = ans_2;
                cnt_2++;
            }
            if (q[cnt] != ans) {
                q[++cnt] = ans;
            }
        }
        cout << q[cnt] << endl;
    }
    return 0;
}