#include<bits/stdc++.h>
using namespace std;
int t, a[4];
int m, d[16];
char c[3];
int f[16][100010];
int cs[9], id[9] = { 1,2,4,8,10,5,12,3,15 };
void ckmin(int& x, int y)
{
  x = min(x, y);
}
int main()
{
  scanf("%d%d%d%d%d", &t, &a[0], &a[1], &a[2], &a[3]);
  cs[0] = cs[1] = cs[2] = cs[3] = a[0];
  cs[4] = cs[5] = a[2]; cs[6] = cs[7] = a[1]; cs[8] = a[3];
  memset(f, 127, sizeof(f));
  f[15][0] = 0;
  for (int i = 0;i < (1 << 16);i++)
    for (int j = 0;j < 16;j++)
      if (i & (1 << j) || (i == 0 && j == 15))
      {
        for (int k = 0;k < 9;k++)
        {
          ckmin(f[j ^ id[k]][i | (1 << (j ^ id[k]))], f[j][i] + cs[k]);
        }
      }
  for (int i = 1;i < 16;i++)
    for (int j = 0;j < (1 << 16);j++)
      f[0][j] = min(f[0][j], f[i][j]);
  for (int i = 0;i < 16;i++)
    for (int j = 0;j < (1 << 16);j++)
      if (j & (1 << i))
        ckmin(f[0][j ^ (1 << i)], f[0][j]);
  while (t--)
  {

    scanf("%d", &m);
    int o = 0;
    while (m--)
    {
      int tmp = 0;
      for (int i = 0;i < 2;i++)
      {
        scanf("%s", c);
        for (int j = 0;j < 2;j++)
          tmp = tmp * 2 + c[j] - '0';
      }
      o ^= (1 << tmp);
    }
    printf("%d\n", f[0][o]);
  }
  return 0;
}