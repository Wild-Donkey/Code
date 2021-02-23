#pragma warning(disable:4996)
#include <map>
//#includ<··>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool z[20005];
char ch;
int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n / i; j++)
            z[i * j] = 1;//预处理质数表O(nlogn)
    for (int i = 2; i <= n / 3; i++) {//开始累加
        if (!(z[i])) {
            for (int j = i; j <= (n - i) / 2; j++) {
                if (!(z[j])) {
                    if (!(z[n - i - j])) {
                        printf("%d %d %d\n", i, j, n - i - j);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}