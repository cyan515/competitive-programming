#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace atcoder;
using mint=atcoder::modint998244353;
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
  string s;cin>>s;
  int n=s.size();
  vector dp(3,fenwick_tree<mint>(n));
  rep(i,n){
    dp.at(s.at(i)-'a').add(i,1);
    int j,k;
    if(s.at(i)=='a')j=1,k=2;
    if(s.at(i)=='b')j=0,k=2;
    if(s.at(i)=='c')j=0,k=1;
    dp.at(s.at(i)-'a').add(i,dp.at(j).sum(0,i)+dp.at(k).sum(0,i));
    // rep(ii,3){
    //   rep(jj,n){
    //     cout<<dp.at(ii).sum(jj,jj+1).val()<<" ";
    //   }
    //   cout<<endl;
    // }
  }
  mint ans=0;
  rep(i,3)ans+=dp.at(i).sum(0,n);
  cout<<ans.val()<<endl;

  return 0;
}
