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
  string s;cin>>s;
  int n = 26;
  int ans = 0;
  int cur;
  rep(i,n) {
    if(s.at(i)=='A') cur=i;
  }
  reps(i,1,n) {
    rep(j,26) {
      if(s.at(j)=='A'+i) {
        ans += abs(cur-j);
        cur = j;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
