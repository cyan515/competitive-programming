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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;cin>>n;
  vector<ll>a(n),b(n);cin>>a>>b;
  ll diff=0;
  rep(i,n)diff+=a.at(i)-b.at(i);
  vector<ll>ans(n);
  rep(i,n)ans.at(i)=1;
  if(diff>0){
    cout<<Yes<<endl;
    rep(i,n){
      if(i)cout<<" ";
      cout<<ans.at(i);
    }
    return 0;
  }
  bool ok=false;
  rep(i,n){
    if(a.at(i)>b.at(i)){
      ans.at(i)=1000000000000000000LL;
      ok=true;
      break;
    }
  }
  if(ok){
    cout<<Yes<<endl;
    rep(i,n){
      if(i)cout<<" ";
      cout<<ans.at(i);
    }
  }else {
    cout<<No<<endl;
  }

  return 0;
}
