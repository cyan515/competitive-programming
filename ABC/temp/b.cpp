#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
#include <atcoder/fenwicktree>
using namespace atcoder;
using mint = modint998244353;
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

//https://atcoder.jp/contests/pakencamp-2023-day1/tasks/pakencamp_2023_day1_b
int main() {
  int n;cin>>n;
  int a,b,c,d;cin>>a>>b>>c>>d;
  a--;b--;c--;d--;
  if(a>b) swap(a,b);
  bool flg = false;
  auto f = [&n](int& x) -> void {
    x = (x+1)%n;
  };
  rep(i,n) {
    flg |= a<c&&c<b&&c<b&&b<d;
    f(a);
    f(b);
    f(c);
    f(d);
  }
  if(flg) cout << 4 << endl;
  else cout << 3 << endl;
  
  return 0;
}
