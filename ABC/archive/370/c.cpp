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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  string s,t;cin>>s>>t;
  int n = s.size();
  vector<string> ans;
  while(s!=t) {
    bool flg = false;
    rep(i,n) {
      if(s.at(i)>t.at(i)) {
        s.at(i) = t.at(i);
        ans.push_back(s);
        flg = true;
        break;
      }
    }
    if(flg) continue;
    rep(i,n) {
      if(s.at(n-1-i)<t.at(n-1-i)) {
        s.at(n-1-i) = t.at(n-1-i);
        ans.push_back(s);
        break;
      }
    }
  }
  cout << ans.size() << endl;
  rep(i,ans.size()) cout << ans.at(i) << endl;

  return 0;
}
