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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  int d;cin>>d;
  vector<int> a(n);cin>>a;
  ll ans = 0;
  int r = 0;
  map<int,int> mp;
  rep(l,n) {
    while(r<n) {
      if(mp.empty()) {
        mp[a.at(r)]++;
        r++;
        continue;
      }
      bool ok = true;
      auto it = mp.lower_bound(a.at(r));
      if(it!=mp.end()) {
        ok &= abs((*it).first-a.at(r))>=d;
      }
      if(it!=mp.begin()) {
        it--;
        ok &= abs((*it).first-a.at(r))>=d;
      }
      if(!ok) break;
      mp[a.at(r)]++;
      r++;
    }
    ans += r-l;
    if(--mp[a.at(l)]==0) mp.erase(a.at(l));
  }
  cout << ans << endl;

  return 0;
}
