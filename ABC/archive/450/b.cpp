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
  int n;cin>>n;
  vector d(n,vector<ll>(n,INF));
  rep(i,n)reps(j,i+1,n){
    cin>>d.at(i).at(j);
    d.at(j).at(i)=d.at(i).at(j);
  }
  rep(a,n)reps(b,a+1,n)reps(c,b+1,n){
    if(d.at(a).at(b)+d.at(b).at(c)<d.at(a).at(c)){
      cout<<Yes<<endl;
      return 0;
    }
  }
  cout<<No<<endl;

  return 0;
}
