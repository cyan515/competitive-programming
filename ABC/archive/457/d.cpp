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
  ll n,k;cin>>n>>k;
  vector<ll>a(n);cin>>a;
  ll ng=LINF;
  ll ok=1;
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    ll cnt=0;
    rep(i,n){
      if(mid-a.at(i)<=0)continue;
      cnt+=(mid-a.at(i)+i+1-1)/(i+1);
      if(cnt>k)break;
    }
    if(cnt>k)ng=mid;
    else ok=mid;
  }
  cout<<ok<<endl;

  return 0;
}
