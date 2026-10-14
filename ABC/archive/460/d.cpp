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
  ll h,w;cin>>h>>w;
  vector<string>s(h);cin>>s;
  auto in=[&](unsigned i,unsigned j)->bool{
    return i<h&&j<w;
  };
  rep(_,1){
    rep(i,h)rep(j,w){
      if(s.at(i).at(j)=='#')continue;
      reps(di,-1,2)reps(dj,-1,2){
        if(di==0&&dj==0)continue;
        int ni=i+di;
        int nj=j+dj;
        if(!in(ni,nj))continue;
        if(s.at(ni).at(nj)=='#')s.at(i).at(j)='x';
      }
    }
    rep(i,h)rep(j,w){
      if(s.at(i).at(j)=='#')s.at(i).at(j)='.';
      else if(s.at(i).at(j)=='x')s.at(i).at(j)='#';
    }
  }
  vector dists(h,vector<int>(w,INF));
  queue<pair<int,int>>q;
  rep(i,h)rep(j,w)if(s.at(i).at(j)=='#')q.push(pair(i,j)),dists.at(i).at(j)=0;
  if(q.size()==0){
    rep(i,h)rep(j,w){
      cout<<'.';
      if(j==w-1)cout<<endl;
    }
    return 0;
  }
  while(q.size()){
    auto [vi,vj]=q.front();q.pop();
    reps(di,-1,2)reps(dj,-1,2){
      int ni=vi+di;
      int nj=vj+dj;
      if(!in(ni,nj))continue;
      if(dists.at(ni).at(nj)!=INF)continue;
      dists.at(ni).at(nj)=dists.at(vi).at(vj)+1;
      q.push(pair(ni,nj));
    }
  }
  rep(i,h)rep(j,w){
    cout<<(dists.at(i).at(j)%2==0?'.':'#');
    if(j==w-1)cout<<endl;
  }

  return 0;
}
