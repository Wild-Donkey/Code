# C

$g_i$ 表示 $i$ 的子树的拓扑序数量.

$f_{i, j}$ 表示在整棵树挖去 $i$ 的后代后, $i$ 的拓扑序等于 $j$, 拓扑序数量.

$$
g_i = \frac {(Size_i - 1)!\displaystyle\prod_{Son} g}{\displaystyle\prod_{Son} Size!}
$$

当 $Fa$ 的拓扑序取 $k$ 时, $f_{i, j}$ 中前 $k$ 个位置前面不会再插入点了, 第 $j$ 个位置被 $i$ 占用了.

剩下的 $n - k - 1$ 个位置中, 有 $n + 1 - Size_{Fa} - k$ 个已经填入的点, 还要填入 $\displaystyle\sum_{Bro} Size$ 个点, 共 $n - Size_i - k$ 个点分配给这些部分.

$$
f_{i, j} = \sum_{k = 1}^{\min(j - 1, n + 1 - Size_{Fa})}  f_{Fa, k} \frac {(n - Size_i - k)!}{(n + 1 - Size_{Fa} - k)!\displaystyle\prod_{Bro}Size!} \displaystyle\prod_{Bro}g\\
f_{i, j} = \prod_{Bro}\frac g{Size!} \sum_{k = 1}^{\min(j - 1, n + 1 - Size_{Fa})}  f_{Fa, k} \frac {(n - Size_i - k)!}{(n + 1 - Size_{Fa} - k)!} \displaystyle\\
$$
