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
  string s;cin>>s;
  int ans = 0;
  rep(i,n-2) {
    if(s.at(i)=='A'&&s.at(i+1)=='B'&&s.at(i+2)=='C') ans++;
  }
  while(Q--) {
    int x;cin>>x;x--;
    char c;cin>>c;
    if(s.at(x)!=c) {
      reps(i,max(0,x-2),min(n-2,x+2)) {
        if(s.at(i)=='A'&&s.at(i+1)=='B'&&s.at(i+2)=='C') ans--;
      }
      s.at(x) = c;
      reps(i,max(0,x-2),min(n-2,x+2)) {
        if(s.at(i)=='A'&&s.at(i+1)=='B'&&s.at(i+2)=='C') ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
