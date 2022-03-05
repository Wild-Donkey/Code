#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned long long Mod(998244353);
unsigned m, n, A, B, C, D, t, Cnt(0);
unsigned long long Ans(0);
struct Node {
  vector<Node*> Ed;//连边
  unsigned f[2][4005], L0, R0, L1, R1;//f[i][j] 表示当前节点 (选了/没选) 金币数为 j - 2002 的方案数. 
  /*
  金币数 = 2(块数 - 1) - 点数 (我们把负数的情况考虑在内, 所以要将数组平移 2002)
  为了加速转移, 我们把 f[0] 有实际意义的 j 的区间记为 [L0, R0], f[1] 有意义的 j 的区间记为 [L1, R1]
  */
}N[2005];
inline void DFS(Node* x, Node* Fa) {
  x->f[0][2000] = x->f[1][2001] = 1, x->L0 = x->R0 = 2000, x->R1 = x->L1 = 2001;
  // 这里初始化 f 数组, f[1] f[0] 分别表示单点 x 选和不选的情况
  for (auto i : x->Ed) if (i != Fa) {
    DFS(i, x);
    unsigned iL(min(i->L1, i->L0)), iR(max(i->R1, i->R0));
    // 这里用到了儿子 i 的f[0], f[1], 所以求出儿子 [L0, R0], [L1, R1] 的并
    unsigned TL(x->L1 + iL - 2002), Sz(x->R1 + iR - 2000 - TL + 1), Tmp[Sz];
    /*
    Tmp 数组是防止被更后的 f 值继续参与转移. 
    TL 表示 Tmp[0] 在 x->f[1] 中的目标位置为 x->f[1][Tmp], Sz 为转移后 x->f[1] 的有效状态区间的长度
    */
    memset(Tmp, 0, sizeof(Tmp));
    for (unsigned j(iL); j <= iR; ++j) {// 分别枚举 x->f[1], i->f[0/1] 的下标进行转移
      for (unsigned k(x->L1); k <= x->R1; ++k) {
        unsigned Des(j + k - 2002 - TL);
        /*
        i 和 x 都选, 它们所属连通块合并为一个的转移目标位置在 Tmp 中的映射 
        总块数减少 1, 所以应该是 2((块x + 块i - 1) - 1) - 点x - 点i
        2(块x - 1) - 点x = k - 2002; 2(块i - 1) - 点i = j - 2002
        k + j = 2(块x - 1 + 块i - 1) - 点x - 点i
        所以 2((块x + 块i - 1) - 1) - 点x - 点i = k + j - 4004
        我们需要给这个值加上 2002 的修正得到它在 x->f[1] 中的下标, 然后减去 TL 映射到 Tmp 数组中
        即 k + j - 4004 + 2002 - TL = k + j - 2002 - TL
        */
        Tmp[Des] = (Tmp[Des] + ((unsigned long long)i->f[1][j] * x->f[1][k])) % Mod, Des += 2;
        // + 2 是因为不合并, 所以块数不减少, 所以在前面的基础上少减一个 2
        Tmp[Des] = (Tmp[Des] + ((unsigned long long)i->f[0][j] * x->f[1][k])) % Mod;
      }
    }
    unsigned TL0(x->L0 + iL - 2000), Sz0(x->R0 + iR - 2000 - TL0 + 1), Tmp0[Sz0];
    // 这里仍然是根据枚举 j, k 的上下界算出 f[0] 的映射和有效值区间长度
    memset(Tmp0, 0, sizeof(Tmp0));
    for (unsigned j(iL); j <= iR; ++j) {
      for (unsigned k(x->L0); k <= (x->R0); ++k) {
        unsigned Des(j + k - 2000 - TL0);//这里都不合并所以直接计算不减 2 的 Des
        Tmp0[Des] = (Tmp0[Des] + ((unsigned long long)i->f[0][j] * x->f[0][k])) % Mod;
        Tmp0[Des] = (Tmp0[Des] + ((unsigned long long)i->f[1][j] * x->f[0][k])) % Mod;
      }
    }
    x->L1 = min(i->L1 + x->L1 - 2002, i->L0 + x->L1 - 2000), x->R1 = max(x->R1 + i->R1 - 2002, x->R1 + i->R0 - 2000);
    x->L0 = TL0, x->R0 = TL0 + Sz0 - 1;
    //这个部分是根据枚举的下标和已经算出的 TL 和 Sz 算出 x 的新 [L0, R0], [L1, R1]
    memcpy(x->f[1] + TL, Tmp, Sz << 2);
    memcpy(x->f[0] + TL0, Tmp0, Sz0 << 2);//将新的 DP 值赋进去
  }
  return;
}
inline void Clr() {//清数组
  for (unsigned i(1); i <= n; ++i) N[i].Ed.clear(), memset(N[i].f, 0, sizeof(N[i].f));
  Ans = 0, n = RD();
}
signed main() {
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i < n; ++i) {
      A = RD(), B = RD();
      N[A].Ed.push_back(N + B);
      N[B].Ed.push_back(N + A);
    }
    DFS(N + 1, NULL);
    for (unsigned i(2003); i <= N[1].R0; ++i) Ans = (Ans + (unsigned long long)N[1].f[0][i] * (i - 2002)) % Mod;
    for (unsigned i(2003); i <= N[1].R1; ++i) Ans = (Ans + (unsigned long long)N[1].f[1][i] * (i - 2002)) % Mod;
    // 这里是只统计金币数为正的情况
    printf("%llu\n", (Ans << 1) % Mod);// 我们只计算了一种点, 还有另一种颜色的点, 它们的情况和我们计算的点的情况一一对应, 所以直接乘以 2 即可
  }
  return Wild_Donkey;
}