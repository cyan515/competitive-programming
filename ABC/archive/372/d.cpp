#include <bits/stdc++.h>
#include <atcoder/segtree>
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
using S = ll;
S op(S a,S b) {
  return max(a,b);
}
S e() {
  return -LINF;
}

int main() {
  int n;cin>>n;
  vector<ll> h(n);cin>>h;
  segtree<S,op,e> st(h);
  vector<ll> imos(n+1,0);
  reps(j,1,n) {
    int ok = j;
    int ng = -1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      int ma = st.prod(mid,j);
      if(ma<=h.at(j)) ok = mid;
      else ng = mid;
    }
    imos.at(ok)++;
    imos.at(j+1)--;
  }
  rep(i,n) imos.at(i+1) += imos.at(i);
  rep(i,n) {
    if(i) cout << " ";
    cout << imos.at(i+1);
  }
  cout << endl;

  return 0;
}
