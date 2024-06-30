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

int main() {
  string s,t;cin>>s>>t;
  int n = s.size();
  rep(w,n-1) {
    rep(c,w) {
      string u = "";
      rep(i,n) {
        if(w*i+c>=n) break;
        u += s.at(w*i+c);
      }
      if(t==u) {
        cout << Yes << endl;
        return 0;
      }
    }
  }
  cout << No << endl;

  return 0;
}
