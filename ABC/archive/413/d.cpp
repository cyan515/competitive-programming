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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--) {
    ll n;cin>>n;
    vector<ll> a(n);cin>>a;
    // 公費 -1 に気を付ける!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    map<ll,ll> mp;
    rep(i,n) {
      mp[a.at(i)]++;
    }
    if(mp.size()==2) {
      auto [x,y] = *mp.begin();
      auto [s,t] = *mp.rbegin();
      if(abs(x)==abs(s)&&abs(y-t)<=1) {
        cout << Yes << endl;
        continue;
      }
    }
    // 絶対値の昇順
    sort(all(a),[&](int i,int j) -> bool {
      return abs(i)<abs(j);
    });
    // ll mi = *min_element(all(a));
    // ll ma = *max_element(all(a));
    // ll g = gcd(a.at(0),a.at(1));
    bool ok = true;
    reps(i,1,n-1) {
      ll x = a.at(i-1);
      ll y = a.at(i);
      ll z = a.at(i+1);
      ok &= y*y == x*z;
    }
    
    cout << (ok?Yes:No) << endl;
  }

  return 0;
}
