#include <bits/stdc++.h>
using namespace std;

// UnionFind, able to rewind to the previous state by undo()
// Written for Educational Codeforces 62 F, although not verified yet.
// @see https://atcoder.jp/contests/abc328/submissions/47458831
struct rollbackable_union_find {
  using pint = pair<int, int>;
  vector<int> par, cou;
  stack<pair<int, pint>> history;
  rollbackable_union_find(int N) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
  int leader(int x) const { return (par[x] == x) ? x : leader(par[x]); }
  bool merge(int x, int y) {
    x = leader(x), y = leader(y);
    if (cou[x] < cou[y]) swap(x, y);
    history.emplace(y, pint(par[y], cou[x]));
    return x != y ? par[y] = x, cou[x] += cou[y], true : false;
  }
  void undo() {
    cou[par[history.top().first]] = history.top().second.second;
    par[history.top().first] = history.top().second.first;
    history.pop();
  }
  void reset() {
    while (!history.empty()) undo();
  }
  int size(int x) const { return cou[leader(x)]; }
  bool same(int x, int y) const { return leader(x) == leader(y); }
};