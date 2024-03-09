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
    vector<int> a(n+1);
    a.at(0) = 0;
    reps(i,1,n+1) a.at(i) = s.at(i-1) - '0';
    reps(i,1,n) a.at(i+1) += a.at(i);
    for(int i=n;i>=1;i--) {
      a.at(i-1) += a.at(i)/10;
      a.at(i) %= 10;
    }
    bool flg = false;
    rep(i,n+1) {
      if(a.at(i)!=0) flg = true;
      if(flg) cout << a.at(i);
    }
    cout << endl;
  }

  exit(0);
}
