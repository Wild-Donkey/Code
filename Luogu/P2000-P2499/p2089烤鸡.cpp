#pragma warning(disable:4996)
#include <map>
//#includ<··>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[15], ans[100005][15], u = 0, n;
void record() {
    u++;
    for (int i = 1; i <= 10; i++) {
        ans[u][i] = a[i];
    }
    return;
}
void f(int x, int rest) {
    if (rest <= 10 - x) {
        return;
    }
    if (x == 10) {
        if (rest > 3) {
            return;
        }
        a[x] = rest;
        return record();
    }
    for (int i = 1; i <= 3; i++) {
        a[x] = i;
        f(x + 1, rest - i);
    }
}
int main() {
    scanf("%d", &n);
    f(1, n);
    printf("%d\n", u);
    for (int i = 1; i <= u; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}