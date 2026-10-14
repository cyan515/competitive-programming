#include <cassert>
#include <climits>
#include <sstream>
#include <stdexcept>

#include "../my-library/graph/dijkstra.cpp"
#include "../my-library/graph/tree_diameter.cpp"
#include "../my-library/int128.cpp"
#include "../my-library/longest_increasing_subsequence.cpp"
#include "../my-library/math/eratosthenes.cpp"
#include "../my-library/math/sqr.cpp"
#include "../my-library/rolling_hash.cpp"
#include "../my-library/string/z_algo.cpp"
#include "../my-library/sum_cnt_multiset.cpp"
#include "../my-library/timer.cpp"

int main() {
  {
    vector<vector<pair<ll, int>>> graph(4);
    graph[0] = {{2, 1}, {10, 2}};
    graph[1] = {{3, 2}};
    assert((dijkstra(graph) == vector<ll>{0, 2, 5, LINF}));

    mt19937 random(20260828);
    for (int iteration = 0; iteration < 100; iteration++) {
      const int n = random() % 7 + 1;
      vector<vector<pair<ll, int>>> random_graph(n);
      vector expected(n, vector<ll>(n, LINF));
      for (int i = 0; i < n; i++) expected[i][i] = 0;
      for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
          if (from != to && random() % 3 == 0) {
            const int cost = random() % 20;
            random_graph[from].push_back({cost, to});
            expected[from][to] = min(expected[from][to], static_cast<ll>(cost));
          }
        }
      }
      for (int via = 0; via < n; via++)
        for (int from = 0; from < n; from++)
          for (int to = 0; to < n; to++)
            if (expected[from][via] != LINF && expected[via][to] != LINF)
              expected[from][to] = min(expected[from][to], expected[from][via] + expected[via][to]);
      for (int source = 0; source < n; source++)
        assert(dijkstra(random_graph, {source}) == expected[source]);
    }
  }
  {
    int u = 0, v = 0;
    assert(tree_diameter({}, &u, &v) == 0);
    assert(u == -1 && v == -1);
  }
  {
    assert(parse_i128("-12345678901234567890") < 0);
    ostringstream out;
    out << parse_i128("-12345678901234567890");
    assert(out.str() == "-12345678901234567890");
  }
  {
    const vector<ll> input = {LLONG_MAX - 1, LLONG_MAX, LLONG_MAX};
    assert((longestNonDecreasingSubsequence(input) == input));

    mt19937 random(20260828);
    for (int iteration = 0; iteration < 100; iteration++) {
      const int n = random() % 10;
      vector<ll> values(n);
      for (ll& value : values) value = static_cast<int>(random() % 11) - 5;
      const vector<ll> actual = longestNonDecreasingSubsequence(values);

      int expected_length = 0;
      for (int bits = 0; bits < (1 << n); bits++) {
        vector<ll> candidate;
        for (int i = 0; i < n; i++)
          if (bits >> i & 1) candidate.push_back(values[i]);
        if (is_sorted(candidate.begin(), candidate.end()))
          expected_length = max(expected_length, static_cast<int>(candidate.size()));
      }
      assert(is_sorted(actual.begin(), actual.end()));
      assert(static_cast<int>(actual.size()) == expected_length);
    }
  }
  {
    assert(sqr(0) == 0);
    assert(sqr(15) == 3);
    assert(sqr(LLONG_MAX) == 3037000499LL);
  }
  {
    assert(z_algo("").empty());
    assert(eratosthenes(0) == vector<bool>{false});
  }
  {
    sum_cnt_multiset values({1, 3, 5});
    values.insert(1, 2);
    values.insert(5, 1);
    assert(values.kth_smallest_value(2) == 1);
    assert(values.kth_biggest_sum(2) == 6);
    bool rejected = false;
    try {
      values.insert(2, 1);
    } catch (const out_of_range&) {
      rejected = true;
    }
    assert(rejected);
  }
  {
    rolling_hash<1000000007> hash("abracadabra");
    assert(hash.get(0, 4) == hash.get(7, 11));
    Timer timer;
    timer.start();
    assert(timer.get_time() >= 0.0);
  }
}
