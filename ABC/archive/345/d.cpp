#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  int h,w;cin>>h>>w;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  auto dfs = [h,w](vector<int>& a,vector<int>& b,vector<vector<int>>& g,int v,auto dfs) -> bool {
    if(v==(int)a.size()) {
      bool flg = true;
      rep(i,h) rep(j,w) flg &= g.at(i).at(j)==1;
      return flg;
    }
    int aa = a.at(v);
    int bb = b.at(v);
    bool flg = false;
    rep(i,h) rep(j,w) {
      if(i+aa-1>=h || j+bb-1>=w) continue;
      rep(k,aa) rep(l,bb) if(g.at(i+k).at(j+l)>0) continue;
      rep(k,aa) rep(l,bb) g.at(i+k).at(j+l)++;
      flg |= dfs(a,b,g,v+1,dfs);
      rep(k,aa) rep(l,bb) g.at(i+k).at(j+l)--;
    }
    if(aa==bb) return flg;
    swap(aa,bb);
    rep(i,h) rep(j,w) {
      if(i+aa-1>=h || j+bb-1>=w) continue;
      rep(k,aa) rep(l,bb) if(g.at(i+k).at(j+l)>0) continue;
      rep(k,aa) rep(l,bb) g.at(i+k).at(j+l)++;
      flg |= dfs(a,b,g,v+1,dfs);
      rep(k,aa) rep(l,bb) g.at(i+k).at(j+l)--;
    }
    return flg;
  };
  rep(bit,1<<n) {
    vector g(h,vector<int>(w,0));
    vector<int> aa;
    vector<int> bb;
    int area = 0;
    rep(tile,n) {
      if((bit&(1<<tile))==0) continue;
      aa.push_back(a.at(tile));
      bb.push_back(b.at(tile));
      area += a.at(tile)*b.at(tile);
    }
    if(area!=h*w) continue;
    bool flg = dfs(aa,bb,g,0,dfs);
    if(flg) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
