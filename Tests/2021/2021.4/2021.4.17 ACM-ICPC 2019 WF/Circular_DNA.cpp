#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned n, Cnt(0), Ans(0), Tmp(0), List[1000005], Pos(0);
char Character;
int Sum[1000005], Low[1000005];
struct DNA {
  unsigned Number;  // ��� 
  int SE;           // s or e, ��Ȩֵ 
}a[1000005];
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) { // ���� 
    Character = getchar();
    while ((Character ^ 's') && (Character ^ 'e')) {
      Character = getchar();
    }
    a[i].SE = (Character ^ 's') ? -1 : 1, a[i].Number = RD();
    if(!Low[a[i].Number]) {                   // �����ŵĻ����״γ���
      Low[a[i].Number] = 1, List[++Cnt] = a[i].Number;              // ��¼�ڻ����б��� 
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    Sum[a[i].Number] += a[i].SE, Low[a[i].Number] = (Low[a[i].Number] < Sum[a[i].Number]) ? Low[a[i].Number] : Sum[a[i].Number]; // ����ǰ׺����ʷ��Сֵ 
  }
  for (register unsigned i(1); i <= Cnt; ++i) {// �������  (ö�ٻ�����)
    if(!((Low[List[i]] | Sum[List[i]]) ^ 0)) {// ͬʱ������������ 
      ++Tmp;
    }
  }
  Pos = 1, Ans = Tmp;                         // ���������������н��
  for (register unsigned i(1); i < n; ++i) {  // ö�ٶϵ�, �����Ǵ� i �����ж�, ����ԭ��˻����� a[i] 
    if(!(Sum[a[i].Number] ^ 0)) {             // �Ż�����, �ȼ��� if(Sum[a[i].Number] == 0) 
      if(a[i].SE ^ (-1)) {                    // �Ż�ͬ��, ���� sx ����� 
        if(!(Low[a[i].Number] ^ 0)) {         // ԭ������, �޸ĺ������� 
          --Tmp;
        }
        --Low[a[i].Number];                   // ����޸� Low[x] 
      }
      else {                                  // ���� ex ����� 
        ++Low[a[i].Number];                   // ���޸� Low[x] 
        if(!(Low[a[i].Number] ^ 0)) {         // ԭ����������ƥ��, �������������� 
          ++Tmp;
        }
      }
    }
    if(Tmp > Ans) {                           // �¶ϵ��ϸ�����ԭ�ȲŸ��� 
      Pos = i + 1, Ans = Tmp;
    }
  }
  printf("%u %u", Pos, Ans);
  return Wild_Donkey;
}
