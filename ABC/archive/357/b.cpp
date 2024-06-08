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
  string s;cin>>s;
  int n = s.size();
  int u = 0;
  int l = 0;
  rep(i,n) {
    if('a'<=s.at(i)&&s.at(i)<='z') l++;
    else u++;
  }
  if(l>u) {
    rep(i,n) s.at(i) = tolower(s.at(i));
  } else {
    rep(i,n) s.at(i) = toupper(s.at(i));
  }
  cout << s << endl;

  return 0;
}
