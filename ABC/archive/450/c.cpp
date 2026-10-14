#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll h,w;cin>>h>>w;
  vector<string> s(h+2);
  s.at(0)=string(w+2,'.');
  s.at(h+1)=s.at(0);
  reps(i,1,h+1)cin>>s.at(i);
  reps(i,1,h+1)s.at(i)="."+s.at(i)+".";
  auto conv=[&](int i,int j)->int{
    return i*w+j;
  };
  auto rconv=[&](int i)->pair<int,int>{
    return pair(i/w,i%w);
  };
  h+=2;
  w+=2;
  dsu uf(h*w);
  auto in=[&](unsigned i,unsigned j)->bool{
    return i<h&&j<w;
  };
  rep(i,h)rep(j,w){
    int v=conv(i,j);
    for(auto [di,dj]:dir){
      int ni=i+di;
      int nj=j+dj;
      if(!in(ni,nj))continue;
      int nv=conv(ni,nj);
      if(s.at(i).at(j)==s.at(ni).at(nj))uf.merge(v,nv);
    }
  }
  int ans=0;
  for(auto vec:uf.groups()){
    auto v=vec.front();
    auto [i,j]=rconv(v);
    if(s.at(i).at(j)=='.')ans++;
  }
  ans--;
  cout<<ans<<endl;

  return 0;
}
