#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#define LowBit(x) ((x) & ((~(x)) + 1))
using namespace std;
unsigned n, m, q;
const unsigned Bin[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648};
unsigned a[100050], b[100050], Pos, PL, PR, FindA, FindB, Ans(0), Bench;
char Ch;
inline unsigned RD() {
	char ich(getchar());
	unsigned intmp(0);
	while ((ich < '0') || (ich > '9')) ich = getchar();
	while ((ich <= '9') && (ich >= '0')) {
		intmp = (intmp << 3) + (intmp << 1) + ich - '0';
		ich = getchar();
	}
	return intmp;
}
struct Node {
	unsigned Va, Vb;
	Node *LS, *RS;
} N[200100], *CntN(N - 1);
Node *Build(unsigned L, unsigned R) {
  Node *x(++CntN);
	if(L ^ R) {
    unsigned Mid((L + R)>>1);
    x->LS = Build(L, Mid);
    x->RS = Build(Mid + 1, R);
    x->Va = x->LS->Va | x->RS->Va;
    x->Vb = x->LS->Vb | x->RS->Vb;
	} else {
		while((Ch != '0') && (Ch != '1') && (Ch != '?')) Ch = getchar();
		unsigned Itmp(1);
		while((Ch == '0') || (Ch == '1') || (Ch == '?')) {
			if(Ch ^ '?') {
			  if(Ch ^ '1') x->Va |= Itmp;
        else x->Vb |= Itmp;
			}
			Ch = getchar(), Itmp <<= 1;
		}
	}
	return x;
}
void Qry(Node *x, unsigned L, unsigned R) {
	if((PL <= L) && (R <= PR)) { 
	  FindA |= x->Va, FindB |= x->Vb;
  } else {
    register unsigned Mid((L + R) >> 1);
    if(PR > Mid) {
      Qry(x->RS, Mid + 1, R);
    }
    if(PL <= Mid) {
      Qry(x->LS, L, Mid);
    }
  }
}
void Change(Node *x, unsigned L, unsigned R) {
	if(L ^ R) {
    unsigned Mid((L + R) >> 1);
    if(Pos <= Mid) {
      Change(x->LS, L, Mid);
    } else {
      Change(x->RS, Mid + 1, R);
    }
    x->Va = x->LS->Va | x->RS->Va;
    x->Vb = x->LS->Vb | x->RS->Vb;
  } else {
    x->Va = x->Vb = 0;
    while((Ch != '0')&&(Ch != '1')&&(Ch != '?')) Ch=getchar();
    register unsigned Itmp(1);
    while((Ch == '0')||(Ch == '1')||(Ch == '?')) {
      if(Ch ^ '?') {
        if(Ch ^ '1') x->Va |= Itmp;
        else x->Vb |= Itmp;
      }
      Ch=getchar(), Itmp <<= 1;
    }
	}
}
int main() {
//	freopen("P5522_2.in","r",stdin);
	// freopen(".out","w",stdout);
	n = RD(),	m = RD(), q = RD();
	Bench = (1 << n) - 1;
	Build(1, m);
	for(register int i(1); i <= q; ++i) { 
    if(RD()) {
			Pos = RD();
      Change(N, 1, m);
		} else {
			PL = RD(), PR = RD(), FindA = FindB = 0;
      Qry(N, 1, m);
      if(!(FindA & FindB)) {
        register unsigned Tmp(((~FindA) & (~FindB)) & Bench), Cnt(1);
        while (Tmp) Cnt <<= 1, Tmp ^= LowBit(Tmp);
        Ans ^= Cnt;
      }
		}
	}
	printf("%u\n",Ans); 
	return 0;
}

