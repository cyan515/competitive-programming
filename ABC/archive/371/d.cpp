#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
  
private:
  vector<long long> _sorted;
};

int main() {
  ll n;cin>>n;
  vector<ll> x(n),p(n);cin>>x>>p;
  fenwick_tree<ll> ft(n);
  rep(i,n) ft.add(i,p.at(i));
  coordinate_compression xx(x);
  int Q;cin>>Q;
  while(Q--) {
    ll l,r;cin>>l>>r;r++;
    cout << ft.sum(xx.compress(l),xx.compress(r)) << endl;
  }

  return 0;
}
