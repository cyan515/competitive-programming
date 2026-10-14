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
  int n,m;cin>>n>>m;
  vector<int> r(m),c(m);
  rep(i,m)cin>>r.at(i)>>c.at(i),r.at(i)--,c.at(i)--;
  vector<bool> ur(n,false),uc(n,false);
  int ans=0;
  for(int i=m-1;i>=0;i--){
    ans++;
    if(ur.at(r.at(i))||uc.at(c.at(i)))ans--;
    ur.at(r.at(i))=true;
    uc.at(c.at(i))=true;
  }
  cout<<ans<<endl;

  return 0;
}
