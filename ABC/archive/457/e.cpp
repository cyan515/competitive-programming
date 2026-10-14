#include <bits/stdc++.h>
#include <atcoder/segtree>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
using S=ll;
S op(S a,S b){
  return min(a,b);
}
S e(){
  return LINF;
}
int main() {
  ll n,m;cin>>n>>m;
  vector<ll>l(m),r(m);
  rep(i,m)cin>>l.at(i)>>r.at(i);
  map<int,set<int>>lr,rl;
  map<pair<int,int>,int>cnt;
  rep(i,m){
    lr[l.at(i)].insert(r.at(i));
    rl[r.at(i)].insert(l.at(i));
    cnt[pair(l.at(i),r.at(i))]++;
  }
  segtree<S,op,e>seg(n+1);
  for(auto [k,v]:lr){
    seg.set(k,*v.begin());
  }
  int Q;cin>>Q;
  while(Q--){
    int s,t;cin>>s>>t;
    {
      auto it=cnt.find(pair(s,t));
      if(it!=cnt.end()&&(*it).second>=2){
        cout<<Yes<<endl;
        continue;
      }
      if(it!=cnt.end()){
        auto iit=lr.find(s);
        auto iiit=(*iit).second.lower_bound(t);
        if(iiit!=(*iit).second.begin()){
          cout<<Yes<<endl;
          continue;
        }
        auto p=seg.prod(s+1,t+1);
        if(p<=t)cout<<Yes<<endl;
        else cout<<No<<endl;
        continue;
      }
    }
    auto le=lr.find(s);
    if(le==lr.end()){
      cout<<No<<endl;
      continue;
    }
    auto ri=rl.find(t);
    if(ri==rl.end()){
      cout<<No<<endl;
      continue;
    }
    auto leit=(*le).second.upper_bound(t);
    if(leit==(*le).second.begin()){
      cout<<No<<endl;
      continue;
    }
    leit--;
    auto riit=(*ri).second.lower_bound(s);
    if(riit==(*ri).second.end()){
      cout<<No<<endl;
      continue;
    }
    ll x=*riit;
    ll y=*leit;
    if(y+1>=x)cout<<Yes<<endl;
    else cout<<No<<endl;
  }

  return 0;
}
