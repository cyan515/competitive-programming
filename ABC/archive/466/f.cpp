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
  int T;cin>>T;
  while(T--){
    ll n,x;cin>>n>>x;
    vector<ll>a;
    a.push_back(x+1);
    {
      ll mi=x+1;
      rep(i,n){
        ll aa;cin>>aa;
        if(chmin(mi,aa))a.push_back(aa);
      }
    }
    a.push_back(1);
    ll ans=0;
    ll cnt=1;
    ll hasu=1;
    while(a.size()>2){
      ll m=a.back();a.pop_back();
      ll nm=a.back();a.pop_back();
      ll nnm=a.back();
      ll xx=nnm/nm;
      cnt*=xx;
      cnt+=(nnm-nm*xx)/m;
      a.push_back(nm);
    }
    cout<<cnt<<endl;
  }

  return 0;
}
