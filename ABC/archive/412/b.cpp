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
  string s,t;cin>>s>>t;
  int n = s.size();
  int m = t.size();
  rep(i,n-1) {
    if(islower(s.at(i+1))) continue;
    bool ok = false;
    rep(j,m) {
      ok |= s.at(i)==t.at(j);
    }
    if(!ok) {
      cout << No << endl;
      return 0;
    }
  }
  cout << Yes << endl;

  return 0;
}
