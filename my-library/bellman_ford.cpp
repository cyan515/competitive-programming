#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ベルマンフォード法
// 負閉路の影響を受ける頂点は -LINF
// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/bellman-ford
vector<ll> bellman_ford(const vector<vector<pair<ll,ll>>>& graph, const int& start) {
  const ll LINF = 3001001001001001001;
  int n = graph.size();
  vector<ll> distances(graph.size(), LINF);
	distances.at(start) = 0;

  for(int i=0;i<n;i++) {
		bool changed = false;

    for(int from=0;from<n;from++) for(auto& [cost,to] : graph.at(from)) {
      
			// (LINF + cost) は LINF なので処理しない
			if (distances.at(from) == LINF) continue;

			// to までの新しい距離
			const long long d = distances.at(from) + cost;

			// d が現在の記録より小さければ更新
			if (d < distances.at(to)) {
				distances.at(to) = d;
				changed = true;
			}
    }

		// どの頂点も更新されなかったら終了
		if (!changed) return distances;
	}

	// 頂点数分だけさらに繰り返し, 負閉路の影響を受ける頂点に -LINF を伝播
	for(int i=0;i<n;i++) {
    for(int from=0;from<n;from++) for(auto& [cost, to] : graph.at(from)) {
			if (distances.at(from) == LINF) continue;

			const long long d = (distances.at(from) + cost);

			if (d < distances.at(to)) {
				// 負閉路の影響を受ける頂点を -INF に
				distances.at(to) = -LINF;
			}
		}
	}

	return distances;
}
