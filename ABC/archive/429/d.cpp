#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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

// 座標圧縮
template <typename T>
class coordinate_compression {
public:
  coordinate_compression(const vector<T>& data) {
    _sorted = data;
    sort(_sorted.begin(),_sorted.end());
    _sorted.erase(unique(_sorted.begin(),_sorted.end()),_sorted.end());
  }
  
  /**
   * @fn
   * 受け取った値を座標圧縮した場合いくつになるかを返す。
   * 計算量 O(logN)
   * 
   * @param val 圧縮前の値
   */
  int compress(const T& val) const {
    T ret = lower_bound(_sorted.begin(),_sorted.end(),val) - _sorted.begin();
    return ret;
  }
  
  /**
   * @fn
   * 受け取った値を座標圧縮する前にいくつだったかを返す。
   * 計算量 O(1)
   * 
   * @param val 圧縮後の値
   */
  const T& decompress(const int& val) const {
    return this->_sorted.at(val);
  }
  
  /**
   * @fn
   * 圧縮後の値の種類数を返す。
   */
  size_t size() const {
    return this->_sorted.size();
  }
  
private:
  vector<T> _sorted;
};

using S = ll;
S op(S a,S b) {
  return a+b;
}
S e() {
  return 0LL;
}

int main() {
  ll n,m,c;cin>>n>>m>>c;
  vector<ll> a(n);cin>>a;
  a.push_back(0);
  auto cc = coordinate_compression(a);
  segtree<S,op,e> seg(cc.size()*2);
  rep(i,n) {
    int aa = cc.compress(a.at(i));
    seg.set(aa,seg.get(aa)+1);
    seg.set(aa+cc.size(),seg.get(aa+cc.size())+1);
  }
  ll ans = 0;
  rep(i,cc.size()) {
    auto f = [&](S x) -> bool {
      return x<c;
    };
    int r = seg.max_right(i+1,f);
    ll xx = (i==cc.size()-1)?m:cc.decompress(i+1);
    xx -= cc.decompress(i);
    ans += seg.prod(i+1,r+1)*xx;
  }
  cout << ans << endl;

  return 0;
}
