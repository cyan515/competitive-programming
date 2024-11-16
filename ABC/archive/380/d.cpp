#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
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
  string s;cin>>s;
  int n = s.size();
  vector<ll> nums;
  {
    ll cur = n;
    while(cur<LINF) {
      nums.push_back(cur);
      cur *= 2;
    }
  }
  int Q;cin>>Q;
  vector<char> ans;
  while(Q--) {
    ll k;cin>>k;
    bool flg = false;
    while(k>n) {
      auto it = lower_bound(all(nums),k);
      it--;
      k -= *it;
      flg ^= true;
    }
    k--;
    if(flg) {
      if(islower(s.at(k))) ans.push_back(toupper(s.at(k)));
      else ans.push_back(tolower(s.at(k)));
    } else {
      ans.push_back(s.at(k));
    }
  }
  rep(i,ans.size()) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
