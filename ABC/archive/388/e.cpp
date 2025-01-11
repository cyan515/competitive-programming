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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  ll ok = 0;
  ll ng = n;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    multiset<int> st;
    reps(i,mid,n) st.insert(a.at(i));
    bool flg = true;
    rep(i,mid) {
      auto it = st.lower_bound(a.at(i)*2);
      if(it==st.end()) {
        flg = false;
        break;
      }
      st.erase(it);
    }
    if(flg) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  return 0;
}
