#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  string s,t;cin>>s>>t;
  int n = s.size();
  int ti = 0;
  rep(i,n) {
    if(s.at(i) == t.at(ti) - ('A'-'a')) {
      ti++;
      if(ti==3) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  if(ti==2&&t.at(2)=='X') cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
