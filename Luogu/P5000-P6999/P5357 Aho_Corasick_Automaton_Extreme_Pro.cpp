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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned n, L(0), R(0), Tmp(0), Cnt(0);
char inch;
struct Node;
struct Edge {
  Edge *Nxt;
  Node *To;
}E[200005], *Cnte(E);
struct Node {
  Node *Son[26], *Fa, *Fail;
  char Ch;
  Edge *Fst;
  bool Exist;
  unsigned Size, Times;
}N[200005], *Q[200005], *now(N), *Cntn(N), *Find(N), *Ans[200005];
inline void Clr() {}
unsigned DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  Edge *Sid(x->Fst);  // ö�ٵ�ǰ�ڵ����г��� 
  x->Size = x->Times; // �Լ���ɨ�����ҲҪͳ�� 
  now = x;
  while (Sid) {
    now = Sid->To;
    x->Size += DFS(now);  // ͳ���ӽڵ������ֵ 
    Sid = Sid->Nxt;
  }
  return x->Size;     // �����Լ�������ֵ 
} 
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while (inch < 'a' || inch > 'z') {//�����޹��ַ� 
      inch = getchar();
    }
    now = N;  // �Ӹ���ʼ 
    while (inch >= 'a' && inch <= 'z') {
      inch -= 'a';    // �ַ�ת��Ϊ�±� 
      if(!(now->Son[inch])) { // �½ڵ� 
        now->Son[inch] = ++Cntn;
        Cntn->Ch = inch;
        Cntn->Fa = now;
      }
      now = now->Son[inch]; // ������ 
      inch = getchar();
    }
    if (!(now->Exist)) { //�´� (ԭ����������������β��ģʽ��)
      now->Exist = 1;
    }
    Ans[i] = now; // ��¼�� i ����β���ڽڵ� 
  }
  for (register short i(0); i < 26; ++i) {  // �Ե�һ�������ڵ���б߽紦�� 
    if(N->Son[i]) {           // ���Ķ��� 
      Q[++R] = N->Son[i];     // ��� 
      N->Son[i]->Fail = N;    // Fail ������, ����ֻ�������
      (++Cnte)->Nxt = N->Fst; // �����, �ñ߱�� 
      N->Fst = Cnte;
      Cnte->To = N->Son[i];
    }
  }
  while (L < R) { // BFS ����, ���Զ��� 
    now = Q[++L]; // ȡ���ײ����� 
//    printf("BFS %u %u %u\n", L, R, now - N);
    for (register short i(0); i < 26; ++i) {
      if(now->Son[i]) {
        Q[++R] = now->Son[i];
      }
    }
    if(!(now->Fa)) {
      continue;
    }
    Find = now->Fa->Fail; // �Ӹ��׵� Fail ��ʼ������, ֱ���ҵ� 
    while (Find) {
      if(Find->Son[now->Ch]) {                    // �ҵ��� (�߽�)
//        printf("Got %u %u\n", Find-N, now-N);
        now->Fail = Find->Son[now->Ch];           // ����� (������)
        (++Cnte)->Nxt = Find->Son[now->Ch]->Fst;  // ����� (������) 
        Find->Son[now->Ch]->Fst = Cnte;
        Cnte->To = now;
        break;
      }
      Find = Find->Fail;  // ������ǰ�� 
    }
    if(!(now->Fail)) {
      now->Fail = N;  // �����Ҳ�����Ӧ Fail �Ľڵ�, Fail ��ָ��� 
      (++Cnte)->Nxt = N->Fst;
      N->Fst = Cnte;
      Cnte->To = now;
    }
//    printf("%u Fail %u\n", now-N, (now->Fail) - N);
  }
//  for (register Edge *i(E); i <= Cnte; ++i) {
//    printf("Edge %u %u %u\n", i - E, i->Nxt - E, i->To - N);
//  }
  while (inch < 'a' || inch > 'z') {
    inch = getchar();
  }
  now = N;
  while (inch >= 'a' && inch <= 'z') {  // �Զ���ɨһ�� 
    inch -= 'a';
    if(!now) {  // �����ȫʧ����, ��Ӹ���ʼ�µ�ƥ��, �������ǰ���Ѿ�ƥ��ɹ��Ľڵ����ƥ�� 
      now = N;
    }
//    printf("%u %c\n", now-N, inch + 'a'); 
    while(now) {              // ��ȫʧ��, ���� 
      if(now->Son[inch]) {    // ƥ��ɹ�, ͬ������ 
        now = now->Son[inch]; // �Զ�����Ӧ�ڵ���ַ���ͬ�������� 
        ++(now->Times);       // ��¼�ڵ�ɨ����� 
        break;
      }
      now = now->Fail;        // �� Fail 
    }
    inch = getchar();
  }
  DFS(N); // ͳ�ƻ��������ģʽ�� 
  for (register unsigned i(1); i <= n; ++i) {
    printf("%u\n", Ans[i]->Size); // ����֮ǰ��¼�ĵ� i ��ģʽ��β�ַ���Ӧ�Ľڵ��ָ���ҵ���Ҫ�Ĵ� 
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
