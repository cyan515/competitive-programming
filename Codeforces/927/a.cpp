#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    string s;cin>>s;
    s += "**";
    int ans = 0;
    int i = 0;
    while(1) {
      if(s.at(i+1)=='*'&&s.at(i+2)=='*') break;
      if(s.at(i+1)=='*') {
        if(s.at(i+2)=='@') ans++;
        i+=2;
        continue;
      }
      if(s.at(i+1)=='@') {
        ans++;
        i++;
        continue;
      }
      if(s.at(i+1)=='.') {
        i++;
        continue;
      }
    }
    cout << ans << endl;
  }

  exit(0);
}
