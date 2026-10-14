#include <bits/stdc++.h>
#include <atcoder/modint>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  string s;cin>>s;
  int n=s.size();
  mint ans=0;
  int r=0;
  rep(l,n){
    if(l==r)r++;
    while(r<n&&(r==0||s.at(r-1)!=s.at(r)))r++;
    ans+=r-l;
  }
  cout<<ans.val()<<endl;

  return 0;
}
