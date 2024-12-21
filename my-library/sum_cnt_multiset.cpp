#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

/// @brief 要素の挿入、削除、K 番目に大きい、小さい要素、上位、下位K個の要素の和の取得がO(logN)でできるデータ構造
/// @see https://x.com/cozy_sauna/status/1672555472023601153
/// @see https://github.com/cozysauna/competitive-programming-python/blob/master/graph/sum_cnt_bit.py
class sum_cnt_multiset {
public:
  /// @brief コンストラクタ
  /// @param add_items 今後追加される可能性のある値を全て含んだ vector
  sum_cnt_multiset(const vector<ll>& add_items) {
    vector<ll> sorted_items = add_items;
    sort(sorted_items.begin(), sorted_items.end());
    sorted_items.erase(unique(sorted_items.begin(), sorted_items.end()), sorted_items.end());
    
    N = sorted_items.size();
    for (int i = 0; i < N; ++i) {
      compress[sorted_items[i]] = i + 1;
      original[i + 1] = sorted_items[i];
    }
    
    sum_data.resize(N + 1, 0);
    cnt_data.resize(N + 1, 0);
    all_cnt = 0;
    all_sum = 0;
  }

  /// @brief 集合に値を追加する O(logN)
  /// @param x 追加する値
  /// @param y 追加する個数
  void insert(ll x, int y) {
    all_sum += x * y;
    all_cnt += y;
    
    _insert(sum_data, compress[x], x * y);
    _insert(cnt_data, compress[x], y);
  }

  /// @brief 集合から値を削除する O(logN)
  /// @param x 削除する値
  /// @param y 削除する個数
  void erase(ll x, int y) {
    insert(x, -y);
  }

  ll kth_smallest_value(int k) {
    int i = _lower_bound(cnt_data, k);
    return original[i];
  }

  ll kth_biggest_value(int k) {
    return kth_smallest_value(all_cnt - k + 1);
  }

  ll kth_smallest_sum(int k) {
    k = min(k, all_cnt);
    int i = _lower_bound(cnt_data, k);
    int cnt = _sum(cnt_data, i);
    return _sum(sum_data, i) - original[i] * (cnt - k);
  }

  ll kth_biggest_sum(int k) {
    k = min(k, all_cnt);
    return all_sum - kth_smallest_sum(all_cnt - k);
  }

  void print() {
    for (int i = 1; i <= all_cnt; ++i) {
      cout << kth_smallest_value(i) << " ";
    }
    cout << endl;
  }

private:
  int N;
  unordered_map<ll, int> compress;
  unordered_map<int, ll> original;
  vector<ll> sum_data;
  vector<ll> cnt_data;
  int all_cnt;
  ll all_sum;

  void _insert(vector<ll>& data, int i, ll x) {
    while (i <= N) {
      data[i] += x;
      i += i & -i;
    }
  }

  int _lower_bound(const vector<ll>& data, ll w) {
    if (w <= 0) return 1;
    int i = 0;
    int size = 1 << (32 - __builtin_clz(N));
    while (size > 0) {
      if (i + size <= N && data[i + size] < w) {
        w -= data[i + size];
        i += size;
      }
      size >>= 1;
    }
    return i + 1;
  }

  ll _sum(const vector<ll>& data, int i) {
    ll ret = 0;
    while (i > 0) {
      ret += data[i];
      i -= i & -i;
    }
    return ret;
  }
};
