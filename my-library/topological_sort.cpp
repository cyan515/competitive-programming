#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

/// @brief トポロジカルソート
/// @param graph グラフ
/// @return トポロジカルソートの結果で辞書順最小のもの。グラフが閉路を含む場合は閉路の前まで
/// @note 1.3 トポロジカルソートの結果で辞書順最小のもの
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/topological-sort
vector<int> topological_sort(const vector<vector<int>>& graph) {
  vector<int> in(graph.size());

  for (auto v : graph) for (auto to : v) in.at(to)++;

  priority_queue<int, vector<int>, greater<int>> q;
  rep(i,graph.size()) {
    if(in.at(i) == 0) q.push(i);
  }
  vector<int> result;
  while (q.size()) {
    int from = q.top();q.pop();
    result.push_back(from);
    for(auto to : graph.at(from)) {
      in.at(to)--;
      if(in.at(to) == 0) q.push(to);
    }
  }

  return result;
}
