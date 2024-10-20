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
  int n,Q;cin>>n>>Q;
  int cl = 0;
  int cr = 1;
  int ans = 0;
  while(Q--) {
    char h;cin>>h;
    int t;cin>>t;t--;
    bool flg = false;
    if(h=='L') {
      if(cl==t) continue;
      int x = cl;
      int cnt = 0;
      while(x!=t) {
        x++;
        cnt++;
        x%=n;
        flg |= x==cr;
      }
      if(flg) {
        ans += n-(t-cl+n)%n;
      } else {
        ans += (t-cl+n)%n;
      }
      cl = t;
    } else {
      if(cr==t) continue;
      int x = cr;
      int cnt = 0;
      while(x!=t) {
        x++;
        cnt++;
        x%=n;
        flg |= x==cl;
      }
      if(flg) {
        ans += n-(t-cr+n)%n;
      } else {
        ans += (t-cr+n)%n;
      }
      cr = t;
    }
  }
  cout << ans << endl;

  return 0;
}
