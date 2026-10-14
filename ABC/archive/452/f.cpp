#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
  ll n,k;cin>>n>>k;
  vector<int>p(n);cin>>p;
  rep(i,n)p.at(i)--;
  ll ans=(1+n)*n/2;
  {
    atcoder::fenwick_tree<ll>ft(n);
    ll ri=0;
    ll cur=0;
    rep(le,n){
      while(ri<n&&cur+ft.sum(p.at(ri),n)<k){
        cur+=ft.sum(p.at(ri),n);
        ft.add(p.at(ri),1);
        ri++;
      }
      ans-=max(0LL,ri-le);
      if(le<ri){
        cur-=ft.sum(0,p.at(le));
        ft.add(p.at(le),-1);
      }else ri=le+1;
    }
  }
  {
    atcoder::fenwick_tree<ll>ft(n);
    ll ri=0;
    ll cur=0;
    rep(le,n){
      while(ri<n&&cur+ft.sum(p.at(ri),n)<=k){
        cur+=ft.sum(p.at(ri),n);
        ft.add(p.at(ri),1);
        ri++;
      }
      ans-=n-ri;
      if(le<ri){
        cur-=ft.sum(0,p.at(le));
        ft.add(p.at(le),-1);
      }else ri=le+1;
    }
  }
  cout<<ans<<endl;

  return 0;
}
