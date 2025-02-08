#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
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

  /// @brief 集合に値を追加する O(logN)
  /// @param x 追加する値
  void insert(ll x) {
    insert(x,1);
  }

  /// @brief 集合から値を削除する O(logN)
  /// @param x 削除する値
  /// @param y 削除する個数
  void erase(ll x, int y) {
    insert(x, -y);
  }

  /// @brief 集合から値を削除する O(logN)
  /// @param x 削除する値
  void erase(ll x) {
    erase(x, 1);
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

int main() {
  ll n;cin>>n;
  vector<ll> p(n);cin>>p;
  rep(i,n) p.at(i)--;
  reverse(all(p));
  vector<int> ans(n);
  vector<ll> vec(n);
  rep(i,n) vec.at(i) = i;
  sum_cnt_multiset st(vec);
  rep(i,n) st.insert(i);
  rep(i,n) {
    int v = st.kth_smallest_value(p.at(i)+1);
    ans.at(v) = n-i;
    st.erase(v);
  }
  rep(i,n) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
