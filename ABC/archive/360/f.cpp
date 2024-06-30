#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
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

class coordinate_compression {
public:
  coordinate_compression(const vector<long long>& data) {
    _sorted = data;
    sort(_sorted.begin(),_sorted.end());
    _sorted.erase(unique(_sorted.begin(),_sorted.end()),_sorted.end());
  }
  
  long long compress(long long& val) const {
    long long ret = lower_bound(_sorted.begin(),_sorted.end(),val) - _sorted.begin();
    return ret*2;
  }
  
private:
  vector<long long> _sorted;
};

int main() {
  ll n;cin>>n;
  vector<ll> l(n),r(n);
  rep(i,n) cin>>l.at(i)>>r.at(i);
  vector<ll> lr;
  rep(i,n) lr.push_back(l.at(i)),lr.push_back(r.at(i));
  sort(all(lr));
  coordinate_compression cc(lr);

  return 0;
}
