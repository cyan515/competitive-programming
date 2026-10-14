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
  int n;cin>>n;
  int th = 20000000/max(1,(int)sqrt(n));
  vector<int>x(n),y(n);
  rep(i,n)cin>>x.at(i)>>y.at(i);
  map<int,vector<int>>mp;
  rep(i,n){
    mp[y.at(i)/th].push_back(i);
  }
  for(auto& [k,v]:mp){
    sort(all(v),[&](int i,int j)->bool{
      return x.at(i)<x.at(j);
    });
  }
  bool tgl=true;
  vector<int>ans;
  ans.push_back(0);
  for(auto [k,v]:mp){
    if(!tgl){
      reverse(all(v));
    }
    for(auto ele:v)if(ele!=0)ans.push_back(ele);
    tgl=!tgl;
  }
  rep(i,n){
    if(i)cout<<" ";
    cout<<ans.at(i)+1;
  }
  cout<<endl;
  {
    ll s=0;
    rep(i,n-1){
      s+=abs(x.at(ans.at(i))-x.at(ans.at(i+1)))+abs(y.at(ans.at(i))-y.at(ans.at(i+1)));
    }
    if(s>10000000000LL){
      throw 0;
    }
  }

  return 0;
}
