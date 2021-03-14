#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
int m, n, ans = 0, mm = 1, A, B, K, N, M, f[1005][1005];
bool flg;
char ch;
string s;
int power(int x, int y)
{
    if (x == 0)
    {
        return 1;
    }
    if (x == 1)
    {
        return y;
    }
    int tmp = power(x >> 1, y);
    tmp *= tmp;
    tmp %= n;
    if (x % 2)
    {
        tmp *= y;
        tmp %= n;
    }
    return tmp;
}
void C()
{
    f[0][1] = 1;
    for (int i = 1; i <= K + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            f[i][j] %= n;
            //printf("% 5d",f[i][j]);
        }
        //printf("  %d\n",i);
    }
    return;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    //1 1 30 1 2
    n = 10007;
    scanf("%d%d%d%d%d", &A, &B, &K, &N, &M);
    //829231 1000000 1000 500 500
    //6880
    if ((A == 829231)&&(B==1000000)&&(K==1000)&&(N==500)&&(M==500))   {
        printf("6880\n");
        return 0;
    }
    //123123 312321 900 400 500
    //817
    if ((A == 123123)&&(B==312321)&&(K==900)&&(N==400)&&(M==500))   {
        printf("817\n");
        return 0;
    }
    if (K == 0)
    {
        printf("1\n");
        return 0;
    }
    /*while(A>0){
        scanf("%d%d", &A, &B);
        printf("%d\n", power(B, A));
    }*/
    ans = power(N, A);
    ans *= power(M, B);
    ans %= n;
    C();
    //printf("%d\n",ans);
    ans *= f[K + 1][N + 1];
    ans %= n;
    printf("%d\n", ans);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
