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
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;cin>>T;
  while(T--) {
    ll h,w;cin>>h>>w;
    vector<string> s(h);cin>>s;
    ll ans = 0;
    vector pref(h+1,vector<int>(w+1,0));
    rep(i,h) rep(j,w) {
      pref.at(i+1).at(j+1) = pref.at(i).at(j+1) + pref.at(i+1).at(j) - pref.at(i).at(j) + (s.at(i).at(j)=='#'?1:-1);
    }
    unordered_map<int,int> mp;
    if(h<=w) {
      rep(i,h+1) reps(j,i+1,h+1) {
        rep(k,w+1) {
          ll x = pref.at(j).at(k)-pref.at(i).at(k);
          ans += mp[x]++;
        }
        mp.clear();
      }
    } else {
      rep(i,w+1) reps(j,i+1,w+1) {
        rep(k,h+1) {
          ll x = pref.at(k).at(j)-pref.at(k).at(i);
          ans += mp[x]++;
        }
        mp.clear();
      }
    }
    cout << ans << endl;
  }

  return 0;
}
