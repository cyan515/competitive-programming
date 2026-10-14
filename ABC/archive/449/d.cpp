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
  ll l,r,d,u;cin>>l>>r>>d>>u;r++;u++;
  ll ans=0;
  reps(x,l,r){
    ll s=-abs(x);
    ll t=abs(x)+1;
    if(x%2==0){
      if(s>=u||d>=t){
        if(abs(d)%2==0)ans+=(abs(u-d)+1)/2;
        else ans+=abs(u-d)/2;
      }else if(d<=s&&t<=u){
        ans+=abs(t-s);
        if(abs(t)%2==0)ans+=(abs(u-t)+1)/2;
        else ans+=abs(u-t)/2;
        if(abs(d)%2==0)ans+=(abs(s-d)+1)/2;
        else ans+=abs(s-d)/2;
      }else if(s<d&&t>u){
        ans+=abs(u-d);
      }else if(s<d){
        ans+=abs(t-d);
        if(abs(t)%2==0)ans+=(abs(u-t)+1)/2;
        else ans+=abs(u-t)/2;
      }else{
        ans+=abs(u-s);
        if(abs(d)%2==0)ans+=(abs(s-d)+1)/2;
        else ans+=abs(s-d)/2;
      }
    }else{
      if(s>=u||d>=t){
        if(abs(d)%2==0)ans+=(abs(u-d)+1)/2;
        else ans+=abs(u-d)/2;
      }else if(d<=s&&t<=u){
        if(abs(t)%2==0)ans+=(abs(u-t)+1)/2;
        else ans+=abs(u-t)/2;
        if(abs(d)%2==0)ans+=(abs(s-d)+1)/2;
        else ans+=abs(s-d)/2;
      }else if(s<d&&t>u){
        // nothing
      }else if(s<d){
        if(abs(t)%2==0)ans+=(abs(u-t)+1)/2;
        else ans+=abs(u-t)/2;
      }else{
        if(abs(d)%2==0)ans+=(abs(s-d)+1)/2;
        else ans+=abs(s-d)/2;
      }
    }
    // cerr<<ans<<endl;
  }
  cout<<ans<<endl;

  return 0;
}
