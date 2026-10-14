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
  ll n,k;cin>>n>>k;k--;
  vector a(n,vector<ll>());
  rep(i,n){
    int l;cin>>l;a.at(i).resize(l);cin>>a.at(i);
  }
  vector<ll>c(n);cin>>c;
  ll cur=0;
  rep(i,n){
    ll nx=cur+c.at(i)*a.at(i).size();
    if(cur<=k&&k<nx){
      cout<<a.at(i).at((k-cur)%a.at(i).size())<<endl;
      return 0;
    }
    cur=nx;
  }

  return 0;
}
