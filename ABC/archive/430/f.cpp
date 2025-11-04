#include <bits/stdc++.h>
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

vector<pair<char, int>> run_length(const string& str) {
  int n = (int)str.size();
  vector<pair<char, int>> ret;
  for (int l = 0; l < n;) {
    int r = l + 1;
    for (; r < n && str[l] == str[r]; r++) {};
    ret.push_back({str[l], r - l});
    l = r;
  }
  return ret;
}

int main() {
  int T;cin>>T;
  while(T--) {
    ll n;cin>>n;
    string s;cin>>s;
    auto rl = run_length(s);
    vector<ll> ans(n+1,0);
    rep(i,rl.size()) {
      auto [k,v] = rl.at(i);
      int le = 0;
      int ri = n;
      reps(j,1,v) {
        ans.at(j)++;
        ans.at(n-v+j)--;
      }
      if(k=='R') {
        ri -= v;
      } else if(k=='L') {
        le += v;
      }
      if(i!=0) {
        auto [kk,vv] = rl.at(i-1);
        if(kk=='R') {
          le += vv;
        } else if(kk=='L') {
          ri -= vv;
        }
      }
      ans.at(le)++;
      ans.at(ri)--;
    }
    if(rl.back().first=='R') {
      ans.at(rl.back().second)++;
      ans.at(n)--;
    } else {
      ans.at(0)++;
      ans.at(n-rl.back().second)--;
    }
    rep(i,n) ans.at(i+1) += ans.at(i);
    rep(i,n) {
      if(i)cout<<" ";
      cout<<ans.at(i);
    }
    cout << endl;
  }

  return 0;
}
