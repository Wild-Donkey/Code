def Pow(x, y) :
  print("qwq", y);
  Rt = 1;
  while y :
    if (y & 1) :
      Rt = Rt * x
    x = x * x; y = y >> 1;
  return Rt
a = int(input())
print(Pow(a, int(input())))
