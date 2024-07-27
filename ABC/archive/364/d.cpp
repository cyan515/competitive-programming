#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  sort(all(a));
  map<ll,ll> mp;
  mp[-INF] = 0;
  mp[INF] = n;
  rep(i,n) mp[a.at(i)]++;
  {
    ll tot = 0;
    for(auto [k,v] : mp) {
      mp[k] += tot;
      tot += v;
    }
  }
  while(Q--) {
    ll b,k;cin>>b>>k;
    ll ok = LINF;
    ll ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      ll le = b-mid;
      ll ri = b+mid;
      auto lit = mp.lower_bound(le);
      lit--;
      auto rit = mp.upper_bound(ri);
      rit--;
      ll cnt = (*rit).second - (*lit).second;
      if(cnt>=k) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }

  return 0;
}
