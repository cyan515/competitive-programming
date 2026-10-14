#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
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
  ll n;cin>>n;
  int Q;cin>>Q;
  set<int>allb;
  set<int>allw;
  ll ans=0;
  vector b(n+1,vector<int>()),w(n+1,vector<int>());
  // vector<int>be,we;
  fenwick_tree<ll>be(Q+1),we(Q+1);
  rep(i,n)
  // we.push_back(-1),
  w.at(i+1).push_back(0),
  allw.insert(i+1);
  we.add(0,n);
  reps(cur,1,Q+1){
    int op;cin>>op;
    if(op==1){
      ll r;cin>>r;
      if(!allb.count(r)){
        allw.clear();
        allb.insert(r);
        int lst=b.at(r).size()>=1?b.at(r).back():-1;
        b.at(r).push_back(cur);
        ll inc;
        {
          // auto it=lower_bound(all(we),lst);
          // inc=we.end()-it;
          inc=we.sum(max(0,lst),cur);
        }
        ans+=inc;
        be.add(cur,1);
        if(lst!=-1)be.add(lst,-1);
      }
    }else{
      ll c;cin>>c;
      if(!allw.count(c)){
        allb.clear();
        allw.insert(c);
        int lst=w.at(c).size()>=1?w.at(c).back():-1;
        w.at(c).push_back(cur);
        ll dec;
        {
          // auto it=lower_bound(all(be),lst);
          // dec=be.end()-it;
          dec=be.sum(max(0,lst),cur);
        }
        ans-=dec;
        we.add(cur,1);
        if(lst!=-1)we.add(lst,-1);
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}
