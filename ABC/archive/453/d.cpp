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
  ll si,sj,gi,gj;
  rep(i,h)rep(j,w){
    if(s.at(i).at(j)=='S')si=i,sj=j;
    if(s.at(i).at(j)=='G')gi=i,gj=j;
  }
  // i,j,dir
  queue<tuple<ll,ll,int>>q;
  rep(i,4)q.push(tuple(si,sj,i));
  vector dists(h,vector(w,vector<ll>(4,LINF)));
  vector prev(h,vector(w,vector<tuple<ll,ll,int>>(4,tuple(-2,-2,-2))));
  rep(i,4)prev.at(si).at(sj).at(i)=tuple(-1,-1,-1);
  rep(i,4)dists.at(si).at(sj).at(i)=0;
  auto in=[&](unsigned i,unsigned j)->bool{
    return i<h&&j<w;
  };
  while(q.size()){
    auto [vi,vj,vd]=q.front();q.pop();
    rep(nd,4){
      auto [di,dj]=dir.at(nd);
      int ni=vi+di;
      int nj=vj+dj;
      if(!in(ni,nj))continue;
      if(dists.at(ni).at(nj).at(nd)!=LINF)continue;
      if(s.at(ni).at(nj)=='#')continue;
      if(s.at(vi).at(vj)=='o'&&vd!=nd)continue;
      if(s.at(vi).at(vj)=='x'&&vd==nd)continue;
      dists.at(ni).at(nj).at(nd)=dists.at(vi).at(vj).at(vd)+1;
      prev.at(ni).at(nj).at(nd)=tuple(vi,vj,vd);
      q.push(tuple(ni,nj,nd));
    }
  }
  ll ans=LINF;
  ll curi=gi;
  ll curj=gj;
  ll curd;
  rep(i,4)if(chmin(ans,dists.at(gi).at(gj).at(i)))curd=i;
  if(ans==LINF){
    cout<<No<<endl;
  }else{
    cout<<Yes<<endl;
    string st="";
    while(1){
      auto [ni,nj,nd]=prev.at(curi).at(curj).at(curd);
      if(ni==-1)break;
      if(ni+1==curi)st.push_back('D');
      else if(ni-1==curi)st.push_back('U');
      else if(nj+1==curj)st.push_back('R');
      else if(nj-1==curj)st.push_back('L');
      curi=ni;
      curj=nj;
      curd=nd;
    }
    reverse(all(st));
    cout<<st<<endl;
  }
  
  return 0;
}
