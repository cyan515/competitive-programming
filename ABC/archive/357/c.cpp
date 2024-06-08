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
  int n;cin>>n;
  if(n==0) {
    cout << "#" << endl;
    return 0;
  }
  vector<string> s = {"###","#.#","###"};
  rep(_,n-1) {
    vector<string> nx(s.size()*3,"");
    rep(i,3) rep(j,3) {
      if(i==1&&j==1) {
        string x = string(s.size(),'.');
        rep(k,s.size()) {
          nx.at(i*s.size()+k) += x;
        }
        continue;
      }
      rep(k,s.size()) {
        nx.at(i*s.size()+k) += s.at(k);
      }
    }
    swap(nx,s);
  }
  rep(i,s.size()) cout << s.at(i) << endl;

  return 0;
}
