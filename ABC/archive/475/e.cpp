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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m,k;cin>>n>>m>>k;
  string t;cin>>t;
  vector<string>s(n);cin>>s;
  rep(i,k){
    rep(j,n){
      if(s.at(j).at(i)==t.at(i))s.at(j).at(i)='0';
      else s.at(j).at(i)='1';
    }
  }
  vector<ll>cnt(k,0);
  rep(i,k)rep(j,n)if(s.at(j).at(i)=='o')cnt.at(i)++;
  int Q;cin>>Q;
  while(Q--){
    int i,j;cin>>i>>j;i--;j--;
    if(s.at(i).at(j)=='0'){
      s.at(i).at(j)='1';
      cnt.at(j)--;
    }else{
      s.at(i).at(j)='0';
      cnt.at(j)++;
    }
    ll rem=m;
    bool ok=false;
    
  }

  return 0;
}
