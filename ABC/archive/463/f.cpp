#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
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
  int n;cin>>n;
  vector<ll>a(n),b(n);
  rep(i,n)cin>>a.at(i)>>b.at(i);
  ll ma=-LINF;
  rep(i,n)ma=max({ma,a.at(i),b.at(i)});
  map<string,ll>mp;
  auto f=[&](ll x,ll y)->string {
    string t;
    ll maab=max(x,y);
    ll miab=min(x,y);
    if(miab<=ma-2&&maab==ma-1)t="01";
    else if(miab<=ma-2&&maab==ma)t="02";
    else if(miab==ma-1&&maab==ma-1)t="11";
    else if(miab==ma-1&&maab==ma)t="12";
    else if(miab==ma&&maab==ma)t="22";
    return t;
  };
  rep(i,n){
    auto t=f(a.at(i),b.at(i));
    mp[t]++;
  }
  vector<mint>chowa(100010,0);
  reps(i,1,100010){
    chowa.at(i)=mint(1)/i;
    chowa.at(i)+=chowa.at(i-1);
  }
  rep(i,n){
    auto t=f(a.at(i),b.at(i));
    {
      if(t=="01"){
        if(mp["22"]!=0){
          cout<<0<<" ";
        }else if(a.at(i)<=ma-2){
          cout<<0<<" ";
        }else{
          ll a=mp["01"];
          ll b=mp["02"];
          ll c=mp["11"];
          ll d=mp["12"];
          ll x=b+c+d+1;
          cout<<(mint(1)/2*(mint(1)/2).pow(b+d)*(mint(1)/2).pow(a-1)*mint(2).pow(a-1)*(chowa.at(x+a-1)-chowa.at(x-1))).val()<<" ";
        }
      }
    }
    {
      if(t=="01"){
        if(mp["22"]!=0){
          cout<<0<<" ";
        }else if(b.at(i)<=ma-2){
          cout<<0<<" ";
        }else{
          ll a=mp["01"];
          ll b=mp["02"];
          ll c=mp["11"];
          ll d=mp["12"];
          ll x=b+c+d+1;
          cout<<(mint(1)/2*(mint(1)/2).pow(b+d)*(mint(1)/2).pow(a-1)*mint(2).pow(a-1)*(chowa.at(x+a-1)-chowa.at(x-1))).val()<<" ";
        }
      }
    }
  }

  return 0;
}
