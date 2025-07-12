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
  int n;cin>>n;
  ll len = 0;
  string ans = "";
  rep(i,n) {
    char c;cin>>c;
    ll l;cin>>l;
    if(l>100||len+l>100) {
      cout << "Too Long" << endl;
      return 0;
    }
    len += l;
    rep(j,l) {
      ans += c;
    }
  }
  cout << ans << endl;

  return 0;
}
