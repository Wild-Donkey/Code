#include<bits/stdc++.h>
using namespace std;
unsigned n;
unsigned long long Pen;
struct Submis {
  unsigned long long Time;
  unsigned Prob;
  bool PeoPle, Status;
  const bool operator<(const Submis& x) const {
    return Time < x.Time;
  }
}S[400005];
struct Period {
  unsigned long long L, R;
  int Weight;
}P[400005];
long long Pre[400005];
unsigned StartPos;
bool Up;
struct Node {
  unsigned long long Max;
  Node* LS, * RS, * Fa;
  Node* Find(unsigned L, unsigned R) {
    if (L == R) return this;
    unsigned Mid((L + R) >> 1);
    if (StartPos <= Mid) return LS->Find(L, Mid);
    else return RS->Find(Mid + 1, R);
  }
  void GoRight(unsigned L, unsigned R) {
    if (L == R)
      if (!Fa) {

      }
  }
}N[800005], * CntN(N);
Node* Build(Node* Fat, unsigned L, unsigned R) {
  Node* Cur = (CntN++);
  Cur->Fa = Fat;
  if (L == R) {
    Cur->Max = Pre[L];
    Cur->LS = Cur->RS = NULL;
    return Cur;
  }
  unsigned Mid((L + R) >> 1);
  Cur->LS = Build(Cur, L, Mid);
  Cur->RS = Build(Cur, Mid + 1, R);
  Cur->Max = max(Cur->LS->Max, Cur->RS->Max);
  return Cur;
}
long long Target;

void solve() {
  cin >> n >> Pen;
  unsigned A, B, D;
  unsigned long long C;
  unsigned CntP = 0;
  bool OriginWin;
  for (unsigned i = 1; i <= n; ++i) {
    cin >> A >> B >> C >> D;
    S[i].PeoPle = (A == 2);
    S[i].Prob = B;
    S[i].Time = C;
    S[i].Status = D;
  }
  sort(S + 1, S + n + 1);
  set<unsigned> ZeroProb, OneProb;
  map<unsigned, unsigned> ZeroPen, OnePen;
  unsigned long long LastTime = 0, ZeroTime = 0, OneTime = 0, Delt = 0;
  int LastWeight = 0;
  for (unsigned i = 1; i <= n; ++i) if (S[i].PeoPle) {
    if (ZeroProb.find(S[i].Prob) == ZeroProb.end()) {
      if (S[i].Status) {
        ZeroProb.insert(S[i].Prob), ZeroTime += S[i].Time + ZeroPen[S[i].Prob] * Pen;
        LastWeight--;
        P[CntP].Weight = LastWeight;
        if (S[i].Time != LastTime) {
          P[CntP].L = LastTime;
          P[CntP].R = S[i].Time;
          ++CntP;
        }
      } else ZeroPen[S[i].Prob] += 1;
    }
  } else {
    if (OneProb.find(S[i].Prob) == OneProb.end()) {
      if (S[i].Status) {
        OneProb.insert(S[i].Prob), OneTime += S[i].Time + OnePen[S[i].Prob] * Pen;
        LastWeight++;
        P[CntP].Weight = LastWeight;
        if (S[i].Time != LastTime) {
          P[CntP].L = LastTime;
          P[CntP].R = S[i].Time;
          ++CntP;
        }
      } else OnePen[S[i].Prob] += 1;
    }
  }
  if (OneProb.size() != ZeroProb.size()) {
    cout << -1 << '\n';
    return;
  }
  if (ZeroTime <= OneTime) OriginWin = 0, Delt = OneTime - ZeroTime + 1;
  else OriginWin = 1, Delt = ZeroTime - OneTime;
  Pre[0] = 0;
  for (unsigned i = 0; i < CntP; ++i) {
    Pre[i + 1] = Pre[i] + (OriginWin ? -P[i].Weight : P[i].Weight) * (P[i].R - P[i].L);
  }
  Node* Root = Build(NULL, 0, CntP);
  for (unsigned i = 0; i < CntP; ++i) {
    if ((OriginWin ? -P[i].Weight : P[i].Weight) < 0) continue;
    Target = Pre[i] + Delt;
    StartPos = i;
    Node* Cur = Root->Find(0, CntP);
    Up = 0;
    Root->GoRight(0, CntP);
  }
  unsigned SegL = 0, SegR = 0;
  unsigned long long CurL = 0, CurR = 0;
  long long CurSum = 0;
  while (SegR < CntP) {//L on Edge
    if (CurSum < Delt) {
      (P[SegR].R - CurR)* (OriginWin ? -P[SegR].Weight : P[SegR].Weight);
    }

  }
  return;
}
signed main() {
  unsigned t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}