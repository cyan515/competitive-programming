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

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> vec;
  unordered_set<ll> st;
  auto dfs = [&](auto f,int v) -> void {
    if(v==n) {
      ll ans = 0;
      rep(i,vec.size()) ans ^= vec.at(i);
      st.insert(ans);
      return;
    }
    rep(i,vec.size()) {
      vec.at(i) += a.at(v);
      f(f,v+1);
      vec.at(i) -= a.at(v);
    }
    vec.push_back(a.at(v));
    f(f,v+1);
    vec.pop_back();
  };
  dfs(dfs,0);
  cout << st.size() << endl;

  return 0;
}
