#include <iostream>
using namespace std;
#include <cstring>
#include <limits>
#include <type_traits>
template <typename... args>
using checkconcept = void;
template <typename, typename enabler, template <class...> class...>
struct _require_impl : std::false_type {};
template <typename T, template <class...> class... concepts>
struct _require_impl<T, checkconcept<concepts<T>...>, concepts...>
    : std::true_type {};
template <typename T, template <class...> class... concepts>
constexpr bool require_v = _require_impl<T, void, concepts...>::value;
template <typename T, template <class...> class... concepts>
using require_t = typename std::enable_if<require_v<T, concepts...>>::type;
#define is_havemember(expr) typename = decltype(T expr)
#define defconcept(name, expr)            \
  template <class T, is_havemember(expr)> \
  struct name {}
#define andconcept(name, ...)       \
  template <class T, ##__VA_ARGS__> \
  struct name {}
#define require(T, ...) typename = require_t<T, ##__VA_ARGS__>
#define logicrequire(...) require(T, ##__VA_ARGS__)
#define FCONCEPT_DEF

#include <cerrno>
#include <type_traits>
#ifndef FCONCEPT_DEF
#include "concept.hpp"
#endif
#include <vector>
namespace fgrp {
andconcept(edge_c, is_havemember({}.u), is_havemember({}.v));
andconcept(weighted_edge_c, logicrequire(edge_c), is_havemember({}.weight));
namespace tags {
struct directed {};
struct undirected {};
}  // namespace tags
template <class E, class = tags::directed, class = void>
struct edge_set {
  static_assert(require_v<E, edge_c>,
                "The type of edge is not match the requests.");
};
template <class E>
struct edge_set<E, tags::directed, require_t<E, edge_c>> {
  using edge_t = E;
  std::vector<E> edges;
  std::vector<std::vector<unsigned>> headers;
  edge_set(int n = 0) : headers(n) {}
  template <typename... Args>
  void add(Args &&...args) {
    edges.emplace_back(std::forward<Args>(args)...);
    headers[edges.back().u].push_back(edges.size() - 1);
  }
  const std::vector<unsigned> &edges_of(int u) { return headers[u]; }
  template <typename Func>
  void for_edges(int u, const Func f) {
    for (auto it : edges_of(u)) f(edges[it]);
  }
};
template <typename E>
struct netflow : public edge_set<E> {
  static_assert(require_v<E, weighted_edge_c>, "Need be weighted");
  netflow(int n = 0) : edge_set<E>(n) {}
  template <typename... Args>
  void add(Args &&...args) {
    E t{std::forward<Args>(args)...};
    edge_set<E>::add(t);
    std::swap(t.u, t.v);
    t.weight = 0;
    edge_set<E>::add(t);
  }
};
struct basic_edge_t {
  int u, v;
};
template <typename T>
struct weighted_edge_t {
  int u, v;
  T weight;
};
using directed_graph = edge_set<basic_edge_t>;
using graph = directed_graph;
}  // namespace fgrp
#define FGRAPH_DEF

#ifndef FGRAPH_DEF
#include "fgrp.hpp"
#endif
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
namespace fgrp {
template <typename E>
std::decay_t<decltype(std::declval<E>().weight)> maxflow(netflow<E> &net,
                                                         int target,
                                                         int starter = 0) {
  using W = std::decay_t<decltype(std::declval<E>().weight)>;
  std::vector<int> dis(net.headers.size()), gap(net.headers.size() + 1);
  std::queue<int> q;
  const auto bfs = [&]() {
    dis[target] = 1;
    q.push(target);
    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      ++gap[dis[u]];
      net.for_edges(u, [&](E &e) {
        if (!dis[e.v]) {
          dis[e.v] = dis[u] + 1;
          q.push(e.v);
        }
        return true;
      });
    }
  };
  bool continuous = true;
  const std::function<W(int, W)> dfs = [&](int u, W delta) {
    if (u == target) return delta;
    W pasf{};
    for (unsigned i = 0; delta && i < net.headers[u].size(); ++i) {
      const unsigned id = net.headers[u][i];
      E &e = net.edges[id];
      if (!e.weight || dis[e.v] != dis[u] - 1) continue;
      const W f = dfs(e.v, std::min(delta, e.weight));
      delta -= f;
      pasf += f;
      e.weight -= f;
      net.edges[id ^ 1].weight += f;
    }
    if (delta) {
      --gap[dis[u]];
      if (!gap[dis[u]]) continuous = false;
      ++dis[u];
      ++gap[dis[u]];
    }
    return pasf;
  };
  W ans{};
  bfs();
  while (continuous) ans += dfs(starter, std::numeric_limits<int>::max());
  return ans;
}
}  // namespace fgrp

#include <bits/stdc++.h>
using namespace std;
using namespace fgrp;
int n, m;
long long c, d, rans(0x7f7f7f7f7f7f7f7f);
constexpr int maxn = 256;
char mp[maxn][maxn];
typedef netflow<weighted_edge_t<int>> net_t;
int res = 0;
int getfill(int k) {
  net_t net(n + m + 2);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (mp[i][j] == '.') net.add(i + 1, n + j + 1, 1);
  for (int i = 1; i <= n; ++i) net.add(1, i + 1, k);
  for (int j = 1; j <= m; ++j) net.add(n + j + 1, n + m + 2, k);
  long long Tmp(maxflow(net, n + m + 1, 1)), Ans((k * c) + (res - Tmp) * d);
  rans = min(Ans, rans);
  return rans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  cin >> c >> d;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> mp[i][j], res += (mp[i][j] == '.');
  int l = 0, r = max(n, m);
  while (l <= r) {
    const int mid = (l + r) / 2;
    if (getfill(mid + 1) < getfill(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << rans << endl;
  return 0;
}