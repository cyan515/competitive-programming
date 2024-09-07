#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
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

int main() {
  int n;cin>>n;
  ll k;cin>>k;
  vector<ll> a(n);cin>>a;
  vector<ll> pref = a;
  rep(i,n-1) pref.at(i+1) += pref.at(i);
  map<int,vector<int>> mp;
  mint ans = 1;
  rep(i,n-1) ans *= 2;
  vector<int> cnt(n+1,0);
  rep(i,n) {
    auto vec = mp[pref.at(i)-k];
    for(auto ele : vec) {
      cnt.at(abs(i-ele)+1)++;
    }
    mp[pref.at(i)].push_back(i);
  }
  rep(i,n) {
    auto tmp = pow_mod(2,n-1-i,MOD)*cnt.at(i);
    ans -= tmp;
  }
  cout << ans.val() << endl;

  return 0;
}
