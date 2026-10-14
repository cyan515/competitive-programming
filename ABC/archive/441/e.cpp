#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  string s;cin>>s;
  vector<int> a(n+1);
  rep(i,n) {
    if(s.at(i)=='A') a.at(i+1)=1;
    else if(s.at(i)=='B') a.at(i+1)=-1;
    else a.at(i+1)=0;
  }
  rep(i,n) a.at(i+1) += a.at(i);
  atcoder::fenwick_tree<ll> ft(2*n+100);
  int base = n+50;
  ll ans = 0;
  rep(i,n+1) {
    ans += ft.sum(0,base+a.at(i));
    ft.add(base+a.at(i),1);
  }
  cout << ans << endl;

  return 0;
}
