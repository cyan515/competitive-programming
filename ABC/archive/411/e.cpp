#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
using S = mint;
S op(S a,S b) {
  return a+b;
}
S e() {
  return 0;
}

double reconstruct(atcoder::modint998244353& m) {
  pair<long long, long long> v = {m.mod(), 0};
  pair<long long, long long> w = {m.val(), 1};

  while (w.first * w.first * 2 > m.mod()) {
    long long q = v.first / w.first;
    pair<long long, long long> z = {
      v.first - q * w.first,
      v.second - q * w.second
    };
    v = w;
    w = z;
  }

  if (w.second < 0) {
    w.first *= -1;
    w.second *= -1;
  }

  return (double) w.first / (double) w.second;
}

// 座標圧縮
class coordinate_compression {
public:
  coordinate_compression(const vector<long long>& data) {
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
  long long compress(const long long& val) const {
    long long ret = lower_bound(_sorted.begin(),_sorted.end(),val) - _sorted.begin();
    return ret;
  }
  ll rev(const int& val) const {
    return this->_sorted.at(val);
  }
  int size() {
    return this->_sorted.size();
  }
  
private:
  vector<long long> _sorted;
};

using F = S;
S mapping(F f,S x) {
  return x * f;
}
F comp(F f,F g) {
  return f*g;
}
F id() {
  return 1;
}

int main() {
  int n;cin>>n;
  vector a(n,vector<int>(6));
  rep(i,n) cin>>a.at(i);
  vector<ll> b(n*6);
  
  rep(i,n) rep(j,6) {
    b.at(i*6+j) = a.at(i).at(j);
  }
  b.push_back(0);
  auto cc = coordinate_compression(b);
  int m = cc.size();
  rep(i,n) {
    sort(rall(a.at(i)));
  }
  lazy_segtree<S,op,e,F,mapping,comp,id> seg(m);
  seg.set(0,1);
  mint inv6 = mint(6).inv();
  rep(i,n) {
    int bef = m;
    rep(j,6) {
      int comp = cc.compress(a.at(i).at(j));
      seg.apply(comp,bef,mint(6-j)*inv6);
      seg.set(comp,seg.get(comp)+seg.prod(0,comp)*inv6);
      bef = comp;
    }
    seg.apply(0,bef,0);
  }
  mint ans = 0;
  rep(i,m) {
    ans += cc.rev(i)*seg.get(i);
  }
  cout << ans.val() << endl;
  cout << reconstruct(ans) << endl;

  return 0;
}
