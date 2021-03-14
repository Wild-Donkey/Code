#pragma warning(disable:4996)
#include <map>
//#includ<··>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int d[25][25][25];
long long a, b, c;
long long f(long long x, long long y, long long z) {
    if ((x <= 0) || (y <= 0) || (z <= 0)) {
        return d[0][0][0];
    }
    if ((x > 20) || (y > 20) || (z > 20)) {
        return d[20][20][20];
    }
    return d[x][y][z];
}
int main() {
    d[0][0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        d[i][0][0] = 1;
        d[0][i][0] = 1;
        d[0][0][i] = 1;
        for (int j = 1; j <= 20; j++) {
            d[i][j][0] = 1;
            d[i][0][j] = 1;
            d[0][i][j] = 1;
        }
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 1; k <= 20; k++) {
                if ((i < j) && (j < k)) {
                    d[i][j][k] = d[i][j][k - 1] + d[i][j - 1][k - 1] - d[i][j - 1][k];
                }
                else {
                    d[i][j][k] = d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1] - d[i - 1][j - 1][k - 1];
                }
            }
        }
    }
    while (1) {
        cin >> a >> b >> c;
        if ((a == -1) && (b == -1) && (c == -1)) {
            return 0;
        }
        f(0, 0, 0);
        printf("w(%lld, %lld, %lld) = %d\n", a, b, c, f(a, b, c));
    }
    return 0;
}