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
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  ll ok = 0;
  ll ng = INF;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    int cnt = 0;
    rep(i,n) if(a.at(i)>=mid) cnt++;
    if(cnt>=mid) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  return 0;
}
