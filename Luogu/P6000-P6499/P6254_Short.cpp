#include <cstdio>
#include <iostream>
#define Wild_Donkey 0
using namespace std;
unsigned n, Cnt(0), Ans(0), Tmp(0), List[1000005], Pos(0);
char Character;
int Sum[1000005], Low[1000005];
struct DNA {
  unsigned Number;  // ��� 
  int SE;           // s or e, ��Ȩֵ 
}a[1000005];
int main() {
  scanf("%u", &n);
  for (register unsigned i(1); i <= n; ++i) { // ���� 
    Character = getchar();
    while (Character != 's' && Character != 'e') {
      Character = getchar();
    }
    if(Character == 's') {                    // ������ 
      a[i].SE = 1;
    }
    else {                                    // ������ 
      a[i].SE = -1;
    }
    scanf("%u", &a[i].Number);
    if(!Low[a[i].Number]) {                   // �����ŵĻ����״γ���
      Low[a[i].Number] = 1;                   // ���Ǳ�ʾ�����ŵĻ�����ֹ� 
      List[++Cnt] = a[i].Number;              // ��¼�ڻ����б��� 
    }
  }
  Pos = 1;
  for (register unsigned i(1); i <= n; ++i) {
    Sum[a[i].Number] += a[i].SE;              // �ۼ��ܺ� 
    Low[a[i].Number] = min(Low[a[i].Number], Sum[a[i].Number]); // ����ǰ׺����ʷ��Сֵ 
  }
  for (register unsigned i(1); i <= Cnt; ++i) {// �������  (ö�ٻ�����)
    if(Low[List[i]] == 0 && Sum[List[i]] == 0) {// ͬʱ������������ 
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
      Pos = i + 1;
      Ans = Tmp;
    }
  }
  printf("%u %u", Pos, Ans);
  return Wild_Donkey;
}
