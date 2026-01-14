#include<bits/stdc++.h>
using namespace std;
bitset<256> Basis[256], CurBS;
bitset<65536> BasisCon[256], CurS;
unsigned n, m, Ans[256];
struct Route {
  bitset<256> Dots;
  unsigned S, T;
}R[65536], * CntR(R);
vector<Route> Routes;
map<unsigned, unsigned> Val;
struct Node {
  vector<Node*> Sons;
  void DFS(Node* Fa, unsigned Depth);
}N[256], * CurNode;
void Node::DFS(Node* Fa, unsigned Depth) {
  if (this - N > 1) CurBS[this - N - 2] = 1;
  if (Depth == m) {
    CntR->Dots = CurBS;
    CntR->S = CurNode - N;
    CntR->T = this - N;
    ++CntR;
    if (this - N > 1) CurBS[this - N - 2] = 0;
    return;
  }
  for (auto i : Sons) if (i != Fa) i->DFS(this, Depth + 1);
  if (this - N > 1) CurBS[this - N - 2] = 0;
  return;
}
void Say(string S) {
  cout << S;
  cout.flush();
}
unsigned XorSet(bitset<65536> S) {
  unsigned Ret = 0;
  for (Route* i = R;i < CntR; ++i) if (S[i - R]) {
    Ret ^= Val[i - R];
  }
  return Ret;
}
map<unsigned, unsigned> Ask(set<unsigned> S) {
  cout << "? " << S.size();
  for (auto i : S) cout << " " << R[i].S << " " << R[i].T;
  cout << '\n';
  cout.flush();
  map<unsigned, unsigned> Ret;
  for (auto i : S) {
    unsigned A;
    cin >> A;
    Ret[i] = A;
  }
  return Ret;
}
void Reply() {
  cout << "!";
  for (unsigned i = 2; i <= n; ++i) cout << " " << Ans[i];
  cout << '\n';
  cout.flush();
}
void DebugBS(bitset<65536> S) {
  for (unsigned i = 0; i < 64; ++i) cerr << S[i];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (unsigned i = 1; i < n; ++i) {
    unsigned A, B;
    cin >> A >> B;
    N[A].Sons.push_back(N + B);
    N[B].Sons.push_back(N + A);
  }
  for (unsigned i = 1; i <= n; ++i) {
    CurNode = N + i;
    CurBS = 0;
    N[i].DFS(NULL, 0);
  }
  for (Route* i = R; i < CntR; ++i) {
    // cerr << "From " << i->S << " To " << i->T << '\n';
    CurS = 0;
    CurS[i - R] = 1;
    for (unsigned j = 0; j < n - 1; ++j) if (i->Dots[j]) {
      if (Basis[j].count()) i->Dots ^= Basis[j], CurS ^= BasisCon[j];
      else {
        Basis[j] = i->Dots, BasisCon[j] = CurS;
        break;
      }
    }
  }
  CurS = 0;
  for (unsigned i = 0; i < n - 1; ++i) {
    if (Basis[i].count() == 0) {
      Say("No\n");
      return 0;
    }
    CurS |= BasisCon[i];
    // cerr << "i " << i << " ";
    // DebugBS(BasisCon[i]);
    // cerr << '\n';
  }
  Say("Yes\n");
  set<unsigned> AskSet;
  for (Route* i = R; i < CntR; ++i) if (CurS[i - R]) AskSet.insert(i - R);
  Val = Ask(AskSet);
  for (unsigned i = n - 2; ~i; --i) {
    for (unsigned j = i + 1; j < n - 1; ++j) if (Basis[i][j]) {
      Basis[i] ^= Basis[j];
      BasisCon[i] ^= BasisCon[j];
    }
    Ans[i + 2] = XorSet(BasisCon[i]);
  }
  Reply();
  return 0;
}
/*
4 1
1 2
2 3
2 4

*/