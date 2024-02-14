#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a.at(i);
    bool flg = true;
    if(n%2) {
      
    } else {
      for(int i=0;i<n;i+=2) {
        if(abs(a.at(i)-a.at(i+1))!=1) flg = false;
      }
    }
    if(flg) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  exit(0);
}
