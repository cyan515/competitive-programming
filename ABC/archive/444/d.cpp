#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
int main() {
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  int m = 500000;
  vector<ll> cnt(m,0);
  rep(i,n) {
    cnt.at(m-a.at(i))++;
  }
  rep(i,m-1) {
    cnt.at(i+1) += cnt.at(i);
  }
  for(int i=m-1;i>0;i--) {
    cnt.at(i-1) += cnt.at(i)/10;
    cnt.at(i) %= 10;
  }
  bool head = false;
  rep(i,m) {
    if(cnt.at(i)!=0) {
      head = true;
    }
    if(head)cout<<cnt.at(i);
  }
  cout<<endl;

  return 0;
}
