#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using mint=atcoder::modint998244353;
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

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
vector<mint> fac, finv, inv;

/// nCk 計算のための前計算処理
/// 計算量は O(n)
void init_comb(int n, int mod) {
  fac.resize(n);
  finv.resize(n);
  inv.resize(n);
  fac.at(0) = fac.at(1) = 1;
  finv.at(0) = finv.at(1) = 1;
  inv.at(1) = 1;
  for (int i = 2; i < n; i++) {
    fac.at(i) = fac.at(i-1) * i;
    inv.at(i) = mod - inv.at(mod%i) * (mod / i);
    finv.at(i) = finv.at(i-1) * inv.at(i);
  }
}

/// nCk を計算して返す。
/// 計算量は O(1)
mint comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac.at(n) * finv.at(k) * finv.at(n-k);
}

/// nHk を計算して返す。
/// 計算量は O(1)
mint hom(int n, int k) {
  return comb(n+k-1, k);
}

int main() {
  init_comb(200100,MOD);
  ll n;cin>>n;
  vector<ll>l(n),r(n);
  rep(i,n)cin>>l.at(i)>>r.at(i);
  ll lma=-LINF;
  ll rmi=LINF;
  vector<ll>x(n+1,LINF);
  rep(i,n){
    chmin(x.at(l.at(i)),r.at(i));
  }
  for(int i=n-2;i>=0;i--){
    chmin(x.at(i),x.at(i+1));
  }
  rep(i,n){
    chmax(lma,l.at(i));
    chmin(rmi,r.at(i));
  }
  mint ans=0;
  vector lr(n,vector<int>());
  rep(i,n){
    lr.at(l.at(i)).push_back(r.at(i));
  }
  atcoder::fenwick_tree<ll>ft(n);
  vector qs(n+1,vector<pair<int,int>>());
  reps(a,1,n){
    ll b=n-a;
    ll mi=min(a,b);
    ll ma=max(a,b);
    if(ma<lma)continue;
    if(rmi<mi)continue;
    if(x.at(mi+1)<ma)continue;
    qs.at(mi).push_back(pair(ma,a));
  }
  rep(mi,n){
    for(auto ele:lr.at(mi))ft.add(ele,1);
    for(auto [ma,a]:qs.at(mi)){
      ll b=n-a;
      // どっちにでも入れる人数
      ll cnt=ft.sum(ma,n);
      // mi の方にしか入れない人数
      ll cnt2=ft.sum(mi,n)-cnt;
      ans+=comb(cnt,mi-cnt2);
    }
  }
  cout<<ans.val()<<endl;

  return 0;
}
