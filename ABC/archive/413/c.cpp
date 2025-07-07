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
  int Q;cin>>Q;
  // cnt,val
  queue<pair<ll,ll>> q;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      ll c,x;cin>>c>>x;
      q.push(pair(c,x));
    } else {
      ll k;cin>>k;
      ll ans = 0;
      while(k>0) {
        auto [c,x] = q.front();
        ll cnt = min(k,c);
        q.front().first -= cnt;
        ans += cnt*x;
        if(q.front().first==0) q.pop();
        k -= cnt;
      }
      cout << ans << endl;
    }
  }

  return 0;
}
