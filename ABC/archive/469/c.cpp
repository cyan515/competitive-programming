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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n;cin>>n;
  string s;cin>>s;
  int ci=0;
  ll p=1;
  vector<ll>ans(n,0);
  rep(i,n){
    if(p==0){
      ans.at(ci)=i;
      p++;
      ci++;
    }
    p--;
    if(s.at(i)=='o')p++;
  }
  rep(i,n)if(ans.at(i)==0)ans.at(i)=n;
  rep(i,n)cout<<ans.at(i)<<endl;

  return 0;
}
