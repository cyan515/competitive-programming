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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{-1,0},{0,1},{0,-1},{1,0},};

int main() {
  int T;cin>>T;
  while(T--){
    ll n,a,b;cin>>n>>a>>b;a--;b--;
    if(n%2){
      cout<<No<<endl;
      continue;
    }
    if((a+b)%2==0){
      cout<<No<<endl;
      continue;
    }
    string ans="";
    int ci=0;
    int cj=0;
    rep(_,a/2){
      ans+=string(n-1,'R');
      ans+="D";
      ans+=string(n-1,'L');
      ans+="D";
      ci+=2;
    }
    rep(_,b/2)ans+="DRUR",cj+=2;
    if(pair(ci,cj+1)==pair(a,b)){
      ans+="DR";
    }else{
      ans+="RD";
    }
    rep(_,(n-b-1)/2)ans+="RURD";
    rep(_,(n-a-1)/2){
      ans+="D";
      ans+=string(n-1,'L');
      ans+="D";
      ans+=string(n-1,'R');
    }
    cout<<Yes<<endl<<ans<<endl;
  }

  return 0;
}
