#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n;cin>>n;
  ll m;cin>>m;
  vector<ll> l(n);
  rep(i,n) cin>>l.at(i);
  
  ll ok = LINF;
  ll ng = 0;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    bool flg = true;
    
    ll row = 1;
    ll col = l.at(0);
    if(col>mid) flg = false;
    reps(i,1,n) {
      if(l.at(i)>mid) {
        flg = false;
        break;
      }
      if(col+1+l.at(i)<=mid) {
        col += 1+l.at(i);
      }
      else col = l.at(i), row++;
    }
    if(row>m) flg = false; 

    if(flg) ok=mid;
    else ng=mid;
  }
  cout << ok << endl;

  exit(0);
}
