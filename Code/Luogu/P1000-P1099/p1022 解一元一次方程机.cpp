#pragma warning(disable:4996)
#include <map>
//#includ<··>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
unsigned long long l;
double ans, k, b, u = 0, t = 1;
bool bj;
char ch;
int main() {
    cin >> s;
    l = int(s.size());
    for (int i = 0; i < l; i++) {
        if (s[i] == '=') {//移项
            u *= t;
            t = 1;
            k += u;
            k = -k;
            b = -b;
            u = 0;
            bj = 0;
        }
        if ((s[i] <= 'z') && (s[i] >= 'a')) {
            ch = s[i];
            bj = 0;
            u *= t;
            b += u;
            if (u == 0) {
                b += t;
            }
            u = 0;
            t = 1;
        }
        if (s[i] == '-') {
            u *= t;
            if (bj)
                k += u;
            t = -1;
            u = 0;
            bj = 0;
        }
        if (s[i] == '+') {
            u *= t;
            if (bj)
                k += u;
            t = 1;
            u = 0;
            bj = 0;
        }
        if ((s[i] <= '9') && (s[i] >= '0')) {
            u *= 10;
            u += s[i] - '0';
            bj = 1;
        }
    }
    if (bj) {
        u *= t;
        k += u;
    }
    ans = -k / b * 1.00;
    if (ans == 0)
        ans = 0;
    //cout << k << endl << b << endl;
    printf("%c=%.3f\n", ch, ans);
    return 0;
}