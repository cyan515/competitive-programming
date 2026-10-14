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
  ll n,m;cin>>n>>m;
  vector<ll>a(n),b(n-1);cin>>a>>b;
  int ans=0;
  vector<ll>c(n-1);
  rep(i,n-1){
    c.at(i)=a.at(i)+a.at(i+1);
    c.at(i)%=m;
  }
  auto c2=c;
  rep(i,n-1){
    if(b.at(i)==c.at(i))continue;
    ans++;
    c.at(i)=1-c.at(i);
    if(i!=n-2)c.at(i+1)=1-c.at(i+1);
  }
  int ans2=1;
  c2.front()=1-c2.front();
  rep(i,n-1){
    if(b.at(i)==c2.at(i))continue;
    ans2++;
    c2.at(i)=1-c2.at(i);
    if(i!=n-2)c2.at(i+1)=1-c2.at(i+1);
  }
  ans=min(ans,ans2);
  cout<<ans<<endl;

  return 0;
}
