#include <cstdio>
#include <iostream>
using namespace std;
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)){
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
const int N = 1e3 + 5;
int n, s, a[N], ans = N, num, fz, fm;
int gcd(int x, int y){
    if (x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.ans", "w", stdout); 
    n = read(), s = read(); a[0] = a[n + 1] = 1e6 + 5;
    for (int i = 1; i <= n; i++){
        a[i] = read();
        if (a[i] < ans){
            ans = a[i];
            num = i;
        }
    }
    int left = num, right = num, l, h, cha;
    while (s){
        h = min(a[left], a[right]);
        while (a[left] == h && left >= 1) left--;
        while (a[right] == h && right <= n) right++;
        l = right - left - 1;
        cha = min(a[left], a[right]) - h;
        if (s > l){
            if (s >= l * cha){
                ans += cha;
                s -= l * cha;
            }
            else {
                ans += s / l, fz = s % l, fm = l;
                int qwq = gcd(fz, fm);
                fz /= qwq, fm /= qwq;
                break;
            }
        }
        else if (s == l){
            ans++; break;
        }
        else {
            fz = s, fm = l;
            int qwq = gcd(fz, fm);
            fz /= qwq, fm /= qwq;
            break;
        }
    }
    printf("%d", ans);
    if (fz) printf("+%d/%d", fz, fm);
    return 0;
}
