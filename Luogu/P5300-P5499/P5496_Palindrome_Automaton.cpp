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
unsigned m, n, Cnt(0), Ans(0), Tmp(0), Key;
bool flg(0);
char a[500005];
struct Node {
  Node *Link, *To[26];
  int Len;
  unsigned LinkLength;
} N[500005], *Order[500005], *CntN(N + 1), *Now(N), *Last(N);
int main() {
  fread(a + 1, 1, 500003, stdin);
  n = strlen(a + 1);
  N[0].Len = -1;
  N[1].Link = N;
  N[1].Len = 0;
  Order[0] = N + 1;
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] < 'a' || a[i] > 'z') { continue; }
    Now = Last = Order[i - 1];
    a[i] -= 'a';
    a[i] = ((unsigned)a[i] + Key) % 26;
    while (Now) {
      if (Now->Len + 1 < i) {
        if (a[i - Now->Len - 1] == a[i]) {  // ��������ַ���Ӧλ���� c
          if (Now->To[a[i]]) {  // ��ת�� c, ���½��ڵ�, ֻ��¼ Order
            Order[i] = Now->To[a[i]];
            flg = 1;  // ��Ǳ�ʾ����û�нڵ㱻�½�
          } else {
            Now->To[a[i]] = ++CntN;    // ת��
            CntN->Len = Now->Len + 2;  // ���� +2 (�������˼� c)
            Order[i] = CntN;           // ��¼ Order
          }
          break;
        }
      }
      Last = Now;  // ��¼��һ���ڵ�, �Ż���һ���� Link ���Ĵ��� (��һ��������
                   // Order_i �� Link)
      Now = Now->Link;  // �� Link
    }
    if (!flg) {  // ���½ڵ�, ���������� Link
      Now = Last;
      while (Now) {
        if (Now->To[a[i]]) {                         // ��ת�� c
          if (Now->To[a[i]]->Len < Order[i]->Len) {  // ���ȺϷ�
            if (a[i - Now->Len - 1] ==
                a[i]) {  // �ýڵ���˰����� Order_i->Link �ĺ�׺
              Order[i]->Link = Now->To[a[i]];
              Order[i]->LinkLength = Now->To[a[i]]->LinkLength + 1;
              break;  // �ҵ� Link
            }
          }
        }
        Now = Now->Link;  // �� Link
      }
      if (!Now) {  // �޺��ʵ� Link, ����ż��
        Order[i]->Link = N + 1;
        Order[i]->LinkLength = 1;
      }
    } else {  // �б��˵�����½ڵ�, ��ձ��
      flg = 0;
    }
    Key = Order[i]->LinkLength;
    printf("%d ", Key);
  }
  return Wild_Donkey;
}
