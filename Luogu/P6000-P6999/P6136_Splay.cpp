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
inline unsigned RD() {  // Fast Read
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
unsigned a[100005], b[100005], m, n, RealN(0), Cnt(0), C, D, t, Tmp(0);
bool Flg(0);
struct Node {
  Node *Fa, *LS, *RS;
  unsigned Value, Size, Count;
} N[1100005], *CntN(N), *Root(N);
Node *Build(register unsigned Le, register unsigned Ri, register Node *Father) {
  if (Le ^ Ri) {  // This Subtree is Bigger than 1
    unsigned Mid((Le + Ri) >> 1);
    Node *x(++CntN);
    x->Count = b[Mid];
    x->Size = b[Mid];
    x->Value = a[Mid];
    x->Fa = Father;
    if (Le ^ Mid) {
      x->LS = Build(Le, Mid - 1, x);
      x->Size += x->LS->Size;
    }
    x->RS = Build(Mid + 1, Ri, x);
    x->Size += x->RS->Size;
    return x;
  }
  (++CntN)->Count = b[Le];  // Single Point
  CntN->Size = b[Le];
  CntN->Value = a[Le];
  CntN->Fa = Father;
  return CntN;
}
inline void Rotate(register Node *x) {  // �Ƹ���ת
  if (x->Fa) {
    Node *Father(x->Fa);  // �ݴ游��
    x->Fa = Father->Fa;   // ��������үү��
    if (Father->Fa) {  // Grandfather's Son (����үү�Ķ���ָ��)
      if (Father == Father->Fa->LS) {  // Left Son
        Father->Fa->LS = x;
      } else {  // Right Son
        Father->Fa->RS = x;
      }
    }
    x->Size = x->Count;  // x �� Size ��һ���� (x->Size = x->LS->Size +
                         // x->RS->Size + x->Count)
    if (x == Father->LS) {  // x is the Left Son, Zag(x->Fa)
      if (x->LS) {
        x->Size += x->LS->Size;
      }
      Father->LS = x->RS, x->RS = Father;
      if (Father->LS) {
        Father->LS->Fa = Father;
      }
    } else {  // x is the Right Son, Zig(x->Fa)
      if (x->RS) {
        x->Size += x->RS->Size;
      }
      Father->RS = x->LS, x->LS = Father;
      if (Father->RS) {
        Father->RS->Fa = Father;
      }
    }
    Father->Fa = x /*���׵��¸����� x*/,
    Father->Size = Father->Count /*Father->Size ��һ����*/;
    if (Father->LS) {  // ���� Father �������Ӷ� Father->Size �Ĺ���
      Father->Size += Father->LS->Size;
    }
    if (Father->RS) {
      Father->Size += Father->RS->Size;
    }
    x->Size += Father->Size;  // Father->Size ���º���ܸ��� x->Size
  }
  return;
}
void Splay(Node *x) {
  if (x->Fa) {
    while (x->Fa->Fa) {
      if (x == x->Fa->LS) {            // Boy
        if (x->Fa == x->Fa->Fa->LS) {  // Boy & Father
          Rotate(x->Fa);
        } else {  // Boy & Mother
          Rotate(x);
        }
      } else {                         // Girl
        if (x->Fa == x->Fa->Fa->LS) {  // Girl & Father
          Rotate(x);
        } else {  // Girl & Mother
          Rotate(x->Fa);
        }
      }
    }
    Rotate(x);
  }
  Root = x;
  return;
}
void Insert(register Node *x, unsigned &y) {
  while (x->Value ^ y) {
    ++(x->Size);         // ��Ϊ����Ԫ�صĸ��ڵ�,
                         // ������С����
    if (y < x->Value) {  // ����������
      if (x->LS) {       // ��������, ������
        x = x->LS;
        continue;
      } else {  // ��������, ���½ڵ�
        x->LS = ++CntN;
        CntN->Fa = x;
        CntN->Value = y;
        CntN->Size = 1;
        CntN->Count = 1;
        return Splay(CntN);
      }
    } else {  // �����������ͬ��
      if (x->RS) {
        x = x->RS;
      } else {
        x->RS = ++CntN;
        CntN->Fa = x;
        CntN->Value = y;
        CntN->Size = 1;
        CntN->Count = 1;
        return Splay(CntN);
      }
    }
  }
  ++(x->Count), ++x->Size;  // ԭ�����ж�Ӧ�ڵ�
  Splay(x);                 // Splay ά�� BST ����ȸ��Ӷ�
  return;
}
void Delete(register Node *x, unsigned &y) {
  while (x->Value ^ y) {
    x = (y < x->Value) ? x->LS : x->RS;
    if (!x) {
      return;
    }
  }
  Splay(x);
  if (x->Count ^ 1) {  // Don't Need to Delete the Node
    --(x->Count), --(x->Size);
    return;
  }
  if (x->LS && x->RS) {  // Both Sons left
    register Node *Son(x->LS);
    while (Son->RS) {
      Son = Son->RS;
    }
    x->LS->Fa = NULL /*Delete x*/,
    Splay(
        Son);  // Let the biggest Node in (x->LS) (the subtree) be the new root
    Root->RS = x->RS;
    x->RS->Fa = Root;  // The right son is still the right son
    Root->Size = Root->Count + x->RS->Size;
    if (Root->LS) {
      Root->Size += Root->LS->Size;
    }
    return;
  }
  if (x->LS) {         // x is The Biggest Number
    x->LS->Fa = NULL;  // x->LS is the new Root
    Root = x->LS;
  }
  if (x->RS) {         // x is The Smallest Number
    x->RS->Fa = NULL;  // x->LS is the new Root
    Root = x->RS;
  }
  return;
}
void Value_Rank(register Node *x, unsigned &y, unsigned &Rank) {
  while (x->Value ^ y) {  // Go Down
    if (y < x->Value) {   // Go Left
      if (x->LS) {
        x = x->LS;
        continue;
      }
      return;  // No more numbers smaller than y, Rank is the rank
    } else {   // Go Right
      if (x->LS) {
        Rank += x->LS->Size;  // The Left Subtree numbers
      }
      Rank += x->Count;  // Mid Point numbers
      if (x->RS) {
        x = x->RS;
        continue;
      }
      return;  // No more numbers bigger than y, Rank is the rank
    }
  }
  if (x->LS) {  // now, x->Value == y
    Rank += x->LS->Size;
  }
  return;
}
void Rank_Value(register Node *x, unsigned &y) {
  while (x) {
    if (x->LS) {
      if (x->LS->Size < y) {  // Not in the Left
        y -= x->LS->Size;
      } else {  // In Left Subtree
        x = x->LS;
        continue;
      }
    }
    if (y > x->Count) {  // In Right Subtree
      y -= x->Count;
      x = x->RS;
      continue;
    }
    return Splay(x);  // Just Look for x
  }
}
void Before(register Node *x, unsigned &y) {
  while (x) {
    if (y <= x->Value) {  // Go left
      if (x->LS) {
        x = x->LS;
        continue;
      }
      while (x) {  // Go Up
        if (x->Value < y) {
          return Splay(x);
        }
        x = x->Fa;
      }
    } else {  // Go right
      if (x->RS) {
        x = x->RS;
        continue;
      }
      return Splay(x);  // Value[x] < Key
    }
  }
}
void After(register Node *x, unsigned &y) {
  while (x) {
    if (y >= x->Value) {  // Go right
      if (x->RS) {
        x = x->RS;
        continue;
      }
      while (x) {  // Go Up
        if (x->Value > y) {
          return Splay(x);
        }
        x = x->Fa;
      }
    } else {  // Go left
      if (x->LS) {
        x = x->LS;
        continue;
      }
      return Splay(x);
    }
  }
}
signed main() {
  register unsigned Ans(0);  // ��¼
  n = RD();
  m = RD();
  a[0] = 0x7f3f3f3f;
  for (register unsigned i(1); i <= n; ++i) {  // ԭ����
    a[i] = RD();
  }
  sort(a + 1, a + n + 1);                      // ����
  for (register unsigned i(1); i <= n; ++i) {  // ȥ��
    if (a[i] ^ a[i - 1]) {                     // A new number
      b[++RealN] = 1;
      a[RealN] = a[i];
    } else {  // Old number
      ++b[RealN];
    }
  }
  a[++RealN] = 0x7f3f3f3f;  // �����ڱ�
  b[RealN] = 1;
  Build(1, RealN, NULL);  // ����
  Root = N + 1;  // ��ʼ���� (���ǵ�һ����, ��Ϊ�ݹ齨���� DFS, ���� DFS ����С��)
  for (register unsigned i(1), A, B, Last(0); i <= m; ++i) {
    A = RD();
    B = RD() ^ Last;
    switch (A) {  // �ֱ��Ƕ�Ӧ�� 6 ������
      case 1: {
        Insert(Root, B);
        break;
      }
      case 2: {
        Delete(Root, B);
        break;
      }
      case 3: {
        Last = 1;
        Value_Rank(Root, B, Last);
        Ans ^= Last;
        break;
      }
      case 4: {
        Rank_Value(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
      case 5: {
        Before(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
      case 6: {
        After(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
