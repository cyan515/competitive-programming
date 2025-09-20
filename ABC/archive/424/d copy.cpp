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
vector<pair<int,int>> dir4 = {{0,1},{0,-1},{1,0},{-1,0},};
vector<pair<int,int>> dir8 = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1},};

int main() {
  int T;cin>>T;
  while(T--) {
    int h,w;cin>>h>>w;
    vector<string> s(h);cin>>s;
    vector dp(h+1,vector<int>(1<<w,INF));
    dp.at(0).at(0) = 0;
    rep(i,h) {
      rep(xbit,1<<w) rep(ybit,1<<w) {
        bool ok = true;
        rep(j,w) {
          if((ybit&(1<<j))!=0 && s.at(i).at(j)=='.') ok = false;
        }
        if(!ok) continue;
        rep(j,w-1) {
          if((xbit&(1<<j))!=0 && (xbit&(1<<(j+1)))!=0 && (ybit&(1<<j))!=0 && (ybit&(1<<(j+1)))!=0) {
            ok = false;
          }
        }
        if(!ok) continue;
        int cnt = 0;
        rep(j,w) {
          if((ybit&(1<<j))==0 && s.at(i).at(j)=='#') cnt++;
        }
        chmin(dp.at(i+1).at(ybit),dp.at(i).at(xbit)+cnt);
      }
    }
    int ans = INF;
    rep(bit,1<<w) ans = min(ans,dp.at(h).at(bit));
    cout << ans << endl;
  }

  return 0;
}
