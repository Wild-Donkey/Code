#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node
{
    int x;
    int y;
    node() {}
    node(int x1, int y1) :x(x1), y(y1) {}
} s, t;
char ch;
bool flg = 0;
int n, m, a;
int main()
{
    scanf("%d%d%d", &n, &m, &a);
    for (int i = 1; i <= a; i++) {
        cout << (i + n - 1) % n + 1 << " " << (i + m - 1) % m + 1 << endl;
    }
    return 0;
}