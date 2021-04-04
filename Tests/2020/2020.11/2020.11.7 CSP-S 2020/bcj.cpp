int Fnd(const int &x) {
  int x_tmp(x);
  while (x_tmp!=Fthr[x_tmp]){
    x_tmp = Fthr[x_tmp];
  }
  Fthr[x] = x_tmp;
  return x_tmp;
}
void Add(const int &x, const int &y) {
  Fthr[Fnd(x)] = Fthr[y];
  return;
}
