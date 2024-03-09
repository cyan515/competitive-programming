#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n,m;cin>>n>>m;
    vector<pair<int,int>> lr(m);
    rep(i,m) cin>>lr.at(i).first>>lr.at(i).second,lr.at(i).second++;
    sort(all(lr));
    int lri = 0;
    vector<int> dp(n+2,0);
    multiset<int> rs;
    reps(i,1,n+1) {
      if(lri<lr.size()) {
        while(lr.at(lri).first==i) {
          rs.insert(lr.at(lri).second);
          lri++;
          if(lri==(int)lr.size()) break;
        }
      }
      auto it = rs.begin();
      
      while((*it)==i) {
        rs.erase(it);
        if(rs.size()==0) break;
        it = rs.begin();
      }
      chmax(dp.at(i+1),dp.at(i));
      it = rs.end();
      if(rs.size()==0) continue;
      it--;
      chmax(dp.at((*it)),dp.at(i)+int(rs.size()));
    }
    int ans = 0;
    rep(i,n+2) chmax(ans,dp.at(i));
    cout << ans << endl;
  }

  exit(0);
}
