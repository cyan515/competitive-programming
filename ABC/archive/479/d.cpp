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
#include <atcoder/segtree>
using namespace atcoder;
using S=ll;
S op(S a,S b){
  return min(a,b);
}
S e(){
  return LINF;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,Q;cin>>n>>Q;
  vector<ll>le(n),ri(n);
  le.at(0)=LINF;
  reps(i,1,n)cin>>le.at(i);
  ri.at(n-1)=LINF;
  rep(i,n-1)cin>>ri.at(i);
  segtree<S,op,e>lseg(n),rseg(n);
  rep(i,n){
    lseg.set(i,le.at(i));
    rseg.set(i,ri.at(i));
  }
  while(Q--){
    int s,t;cin>>s>>t;s--;t--;
    ll ans=LINF;
    if(s<t){
      ans=ri.at(s);
      ans=min(ans,le.at(s)+rseg.prod(0,s));
    }else{
      ans=le.at(s);
      ans=min(ans,ri.at(s)+lseg.prod(s,n));
    }
    cout<<ans<<endl;
  }

  return 0;
}
