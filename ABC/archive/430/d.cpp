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
  ll n;cin>>n;
  vector<ll> x(n+1,0);
  reps(i,1,n+1) cin>>x.at(i);
  vector<ll> memo(n+1,0);
  // place, man num
  map<ll,ll> mp;
  mp[0] = 0;
  ll ans = 0;
  reps(i,1,n+1) {
    int rii = -1;
    int lei = -1;
    {
      auto it = mp.lower_bound(x.at(i));
      if(it!=mp.end()) {
        auto [k,v] = *it;
        rii = v;
        ans -= memo.at(rii);
      }
      it--;
      auto [k,v] = *it;
      lei = v;
      ans -= memo.at(lei);
    }
    
    mp[x.at(i)] = i;
    {
      ll dist = LINF;
      auto it = mp.upper_bound(x.at(i));
      if(it!=mp.end()) {
        auto [k,v] = *it;
        chmin(dist,abs(x.at(i)-k));
      }
      it--;
      it--;
      auto [k,v] = *it;
      chmin(dist,abs(x.at(i)-k));
      memo.at(i) = dist;
      ans += dist;
    }
    {
      ll dist = LINF;
      auto it = mp.upper_bound(x.at(lei));
      if(it!=mp.end()) {
        auto [k,v] = *it;
        chmin(dist,abs(x.at(lei)-k));
      }
      it--;
      if(it!=mp.begin())
      {
        it--;
        auto [k,v] = *it;
        chmin(dist,abs(x.at(lei)-k));
      }
      memo.at(lei) = dist;
      ans += dist;
    }
    if(rii!=-1) {
      ll dist = LINF;
      auto it = mp.upper_bound(x.at(rii));
      if(it!=mp.end()) {
        auto [k,v] = *it;
        chmin(dist,abs(x.at(rii)-k));
      }
      it--;
      it--;
      auto [k,v] = *it;
      chmin(dist,abs(x.at(rii)-k));
      memo.at(rii) = dist;
      ans += dist;
    }
    
    cout << ans << endl;
  }

  return 0;
}
