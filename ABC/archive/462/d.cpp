#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// using S=ll;
// S op(S a,S b){
//   return min(a,b);
// }
// S e(){
//   return LINF;
// }

int main() {
  ll n,d;cin>>n>>d;
  vector<ll>s(n),t(n);
  rep(i,n)cin>>s.at(i)>>t.at(i);
  ll m=1000010;
  vector mp(m,vector<ll>());
  rep(i,n)mp.at(s.at(i)).push_back(t.at(i));
  ll ans=0;
  fenwick_tree<ll>ft(m);
  rep(i,m){
    auto v=mp.at(i);
    for(auto ele:v){
      ft.add(ele,1);
    }
    if(i+d>=m)break;
    ll sm=ft.sum(i+d,m);
    ans+=sm*(sm-1)/2;
  }
  cout<<ans<<endl;
  // vector<ll>imos(m,0);
  // rep(i,n){
  //   imos.at(s.at(i))++;
  //   imos.at(t.at(i))--;
  // }
  // rep(i,m-1){
  //   imos.at(i+1)+=imos.at(i);
  // }
  // segtree<S,op,e>seg(m);
  // rep(i,m)seg.set(i,imos.at(i));
  // ll ans=0;
  // rep(i,m){
  //   if(i+d>m)break;
  //   ll x=seg.prod(i,i+d);
  //   if(x>=2)ans+=x*(x-1)/2;
  // }
  // cout<<ans<<endl;

  return 0;
}
