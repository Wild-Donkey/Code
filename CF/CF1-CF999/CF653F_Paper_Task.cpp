#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
char a[500005];
unsigned Heit[500005], Smal[500005], Stack[500005], *STop(Stack);
unsigned long long Ans(0);
vector<unsigned> b[1000005];
unsigned n, Cnt(0);
inline unsigned RD() {
    unsigned RTmp(0);
    char RChr(getchar());
    while ((RChr < '0') || (RChr > '9')) RChr = getchar();
    while ((RChr >= '0') && (RChr <= '9')) RTmp = (RTmp << 3) + (RTmp << 1) + RChr - 48, RChr = getchar();
    return RTmp;
}
struct Node {
    Node *To[2], *Link;
    vector<Node*> Son;
    unsigned Len, EndPos;
    inline void Add(char x);
    inline void DFS();
}N[1000005], *Que[1000005], **Tl(Que), **Hd(Que), *Last(N), *CntN(N);
inline void Node::Add(char x) {
    Node* Back(Last);
    EndPos = Len = ++Cnt, Last = this;
    while(Back && (!(Back->To[x]))) Back->To[x] = this, Back = Back->Link;
    if(!Back) {Link = N; return;}
    if((Back->Len + 1) == (Back->To[x]->Len)) {Link = Back->To[x]; return;}
    Node *Copy(++CntN), *Cur(Back->To[x]);
    (*Copy) = (*Cur), Copy->EndPos = 0, Copy->Len = Back->Len + 1, Cur->Link = Link = Copy;
    while(Back && (Back->To[x] == Cur)) Back->To[x] = Copy, Back = Back->Link;
}
inline void Node::DFS() {for (auto i:Son) i->DFS(), EndPos = max(EndPos, i->EndPos);}
signed main() {
    n = RD();
    scanf("%s", a + 1);
    for (unsigned i(1); i <= n; ++i) (++CntN)->Add(a[i] -= '(');
    b[Cnt = 500000].push_back(0), Heit[0] = Cnt, Stack[0] = 0xffffffff;
    for (unsigned i(1); i <= n; ++i) {
        if(a[i]) b[--Cnt].push_back(i);
        else b[++Cnt].push_back(i);
        Heit[i] = Cnt;
        while((STop > Stack) && (Heit[*STop] >= Cnt)) --STop;
        Smal[i] = ((*STop) + 1), *(++STop) = i;
    }
    for (Node* i(N + 1); i <= CntN; ++i) i->Link->Son.push_back(i);
    N->DFS();
    for (Node* i(N + 1); i <= CntN; ++i) {
        unsigned R(i->EndPos), LL(max(R - i->Len, Smal[R])), LR(min(R - i->Link->Len - 1, R - 1));
        vector<unsigned>* Wh(b + Heit[R]);
        if(LL > LR) continue;
        Ans += upper_bound(Wh->begin(), Wh->end(), LR) - lower_bound(Wh->begin(), Wh->end(), LL);
    }
    printf("%llu\n", Ans);
    return 0;
}