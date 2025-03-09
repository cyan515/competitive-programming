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
using S = ll;
S op(S a,S b) {
  return max(a,b);
}
S e() {
  return -LINF;
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
    return ret+1;
  }
  
private:
  vector<long long> _sorted;
};

int main() {
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  vector<ll> r(Q),x(Q);
  rep(i,Q) cin>>r.at(i)>>x.at(i);
  vector<int> ord(Q);
  rep(i,Q) ord.at(i) = i;
  sort(all(ord),[&](int ii,int jj) -> bool {
    if(r.at(ii)!=r.at(jj)) return r.at(ii)<r.at(jj);
    else return x.at(ii)<x.at(jj);
  });
  vector<ll> vec;
  rep(i,n) vec.push_back(a.at(i));
  rep(i,Q) vec.push_back(x.at(i));
  coordinate_compression comp(vec);
  segtree<S,op,e> dp(4*100010);
  rep(i,4*100010) dp.set(i,0);
  int Qi = 0;
  vector<ll> ans(Q);
  rep(i,n) {
    ll aa = comp.compress(a.at(i));
    dp.set(aa,max(dp.prod(0,aa)+1,dp.get(aa)));
    while(Qi<Q&&r.at(ord.at(Qi))==i+1) {
      ans.at(ord.at(Qi)) = dp.prod(0,comp.compress(x.at(ord.at(Qi))+1));
      Qi++;
    }
  }
  rep(i,Q) cout << ans.at(i) << endl;

  return 0;
}
