#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using mint=atcoder::modint998244353;
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
// https://algo-logic.info/combination/

vector<long long> fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
void init(int SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(k)
*/
mint nCk(ll n, ll k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    mint ans = 1;
    for (ll i = n; i >= n - k + 1; i--) {
        ans *= i;
    }
    return ans * fact_inv[k];
}

int main() {
  ll n;cin>>n;
  vector<ll>p(n),c(n),d(n);
  p.at(0)=-1;
  rep(i,n-1)cin>>p.at(i+1),p.at(i+1)--;
  cin>>c>>d;
  vector g(n,vector<int>());
  reps(i,1,n){
    g.at(i).push_back(p.at(i));
    g.at(p.at(i)).push_back(i);
  }
  vector<ll>x=c;
  vector<ll>y=d;
  {
    bool ok=true;
    auto dfs=[&](auto self,int v,int par)->void{
      for(auto nv:g.at(v)){
        if(nv==par)continue;
        self(self,nv,v);
      }
      if(par!=-1)x.at(par)+=x.at(v),y.at(par)+=y.at(v);
    };
    dfs(dfs,0,-1);
    rep(i,n)ok&=x.at(i)>=y.at(i);
    if(!ok){
      cout<<0<<endl;
      return 0;
    }
  }
  mint ans=1;
  init(1000100);
  rep(i,n){
    ll ca=x.at(i);
    for(auto ni:g.at(i)){
      if(p.at(i)==ni)continue;
      ca-=y.at(ni);
    }
    if(ca<d.at(i)){
      cout<<0<<endl;
      return 0;
    }
    ans*=nCk(ca,d.at(i));
  }
  cout<<ans.val()<<endl;

  return 0;
}
