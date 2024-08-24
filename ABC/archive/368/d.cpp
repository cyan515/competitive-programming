#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  ll n,k;cin>>n>>k;
  vector g(n,vector<int>());
  rep(i,n-1) {
    int a,b;cin>>a>>b;a--;b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  set<int> st;
  rep(i,k) {
    int v;cin>>v;v--;st.insert(v);
  }
  vector<bool> flg(n,false);
  vector<bool> seen(n,false);
  auto f = [&](auto f,int v) -> bool {
    bool ret = false;
    for(auto nv : g.at(v)) {
      if(seen.at(nv)) continue;
      seen.at(nv) = true;
      ret |= f(f,nv);
    }
    if(st.count(v)) ret = true;
    return flg.at(v) = ret;
  };
  seen.at(*st.begin()) = true;
  f(f,*st.begin());
  int ans = 0;
  rep(i,n) if(flg.at(i)) ans++;
  cout << ans << endl;

  return 0;
}
