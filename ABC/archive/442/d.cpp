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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  atcoder::fenwick_tree<ll> ft(n);
  rep(i,n) ft.add(i,a.at(i));
  while(Q--) {
    int op;cin>>op;
    if(op==1) {
      ll x;cin>>x;x--;
      ll l = ft.sum(x,x+1);
      ll r = ft.sum(x+1,x+2);
      ft.add(x,-l);ft.add(x,r);
      ft.add(x+1,-r);ft.add(x+1,l);
    } else {
      ll l,r;cin>>l>>r;l--;
      cout << ft.sum(l,r) << endl;
    }
  }

  return 0;
}
