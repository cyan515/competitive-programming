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
  ll n,Q;cin>>n>>Q;
  int base=10000000;
  vector<int>on(n);
  rep(i,n)on.at(i)=base+i;
  while(Q--){
    int c,p;cin>>c>>p;c--;p--;
    on.at(c)=p;
  }
  vector<int>ans(n,0);
  map<int,int>mp;
  rep(i,n)mp[on.at(i)]=i;
  rep(i,n){
    int cur=base+i;
    auto it=mp.find(cur);
    int cnt=0;
    while(it!=mp.end()){
      cnt++;
      cur=(*it).second;
      it=mp.find(cur);
    }
    ans.at(i)=cnt;
  }
  rep(i,n){
    if(i)cout<<" ";
    cout<<ans.at(i);
  }
  cout<<endl;

  return 0;
}
