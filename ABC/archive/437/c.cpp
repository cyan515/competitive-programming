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
  int T;cin>>T;
  while(T--) {
    ll n;cin>>n;
    vector<ll> w(n),p(n);
    rep(i,n) cin>>w.at(i)>>p.at(i);
    vector<int> ord(n);
    rep(i,n) ord.at(i) = i;
    sort(all(ord),[&](int i,int j) -> bool {
      return w.at(i)+p.at(i) < w.at(j)+p.at(j);
    });
    int ok = 0;
    int ng = n+1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      ll ws = 0;
      ll ps = 0;
      rep(i,mid) {
        ws += w.at(ord.at(i));
      }
      reps(i,mid,n) {
        ps += p.at(ord.at(i));
      }
      if(ws>ps) ng = mid;
      else ok = mid;
    }
    cout << ok << endl;
  }

  return 0;
}
