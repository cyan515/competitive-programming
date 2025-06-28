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
  int n,m;cin>>n>>m;
  set<pair<int,int>> es;
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    if(u>v) swap(u,v);
    es.insert(pair(u,v));
  }
  vector<int> vs(n);
  int ans = INF;
  vector<int> divs;
  {
    int l = 0;
    int r = 1;
    rep(bit,1<<(n-1)) {
      bool ok = true;
      if((bit&1)!=0) continue;
      if((bit&1<<(n-2))!=0) continue;
      reps(i,1,n) {
        if((bit&(1<<(i-1)))==0) {
          r++;
        } else {
          if(r-l<=2) {
            ok = false;
            break;
          }
          l = r;
          r++;
        }
      }
      if(ok) divs.push_back(bit);
    }
  }
  
  rep(i,n) vs.at(i) = i;
  do {
    for(auto bit : divs) {
      vector<vector<int>> gs;
      gs.push_back({vs.front()});
      int cur = 0;
      reps(i,1,n) {
        if((bit&(1<<(i-1)))!=0) {
          cur++;
          gs.push_back({vs.at(i)});
        } else {
          gs.at(cur).push_back(vs.at(i));
        }
      }
      bool ok = true;
      for(auto v : gs) {
        if(v.size()<=2) ok = false;
      }
      if(!ok) continue;
      int cnt = 0;
      auto ess = es;
      for(auto v : gs) {
        rep(i,v.size()-1) {
          int x = v.at(i);
          int y = v.at(i+1);
          if(x>y) swap(x,y);
          if(!ess.count(pair(x,y))) cnt++;
          else ess.erase(pair(x,y));
        }
        int x = v.back();
        int y = v.front();
        if(x>y) swap(x,y);
        if(!ess.count(pair(x,y))) cnt++;
        else ess.erase(pair(x,y));
      }
      cnt += ess.size();
      ans = min(ans,cnt);
    }
  } while(next_permutation(all(vs)));
  cout << ans << endl;

  return 0;
}
