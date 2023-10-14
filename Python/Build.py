a = []
for i in range (0, 3):
  b = []
  for j in range (0, 3):
    b.append((i * 3 + j + 1)**2)
  a.append(b)

for i in range (0, 3):
  print(a[i])