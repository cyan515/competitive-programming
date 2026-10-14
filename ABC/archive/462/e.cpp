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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--){
    ll a,b,x,y;cin>>a>>b>>x>>y;
    if(a>b){
      swap(a,b);
      swap(x,y);
    }
    x=abs(x);
    y=abs(y);
    ll ans=0;
    ans+=min(x,y)*a*2;
    if(min(x,y)!=x){//min=y
      ll d1=a*((abs(x-y)+1)/2)+b*((abs(x-y))/2);
      ll d2=a*((abs(x-y)+1)/2)+a*3*((abs(x-y))/2);
      ans+=min(d1,d2);
    }
    if(min(x,y)!=y){//min=x
      // ans+=b*((abs(y-x)+1)/2);
      // ans+=a*((abs(y-x))/2);
      ll d1=b*((abs(x-y)+1)/2)+a*((abs(x-y))/2);
      ll d2=a*3*((abs(x-y)+1)/2)+a*((abs(x-y))/2);
      ans+=min(d1,d2);
    }
    cout<<ans<<endl;
  }

  return 0;
}
