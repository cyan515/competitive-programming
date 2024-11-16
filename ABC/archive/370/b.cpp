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
  int n;cin>>n;
  vector a(n,vector<int>());
  rep(i,n) rep(j,i+1) {
    int x;cin>>x;x--;
    a.at(i).push_back(x);
  }
  ll cur = 0;
  rep(i,n) {
    cur = a.at(max(i,cur)).at(min(i,cur));
  }
  cout << cur + 1 << endl;

  return 0;
}
