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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  string s,t;cin>>s>>t;
  int ans = INF;
  rep(le,n) {
    int ri = le+m;
    if(ri>n) continue;
    int cnt = 0;
    string ss = s.substr(le,m);
    rep(i,m) {
      if(ss.at(i)>=t.at(i)) {
        cnt += ss.at(i) - t.at(i);
      } else {
        cnt += ss.at(i) - t.at(i) + 10;
      }
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;

  return 0;
}
