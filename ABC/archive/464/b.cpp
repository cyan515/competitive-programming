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
  int h,w;cin>>h>>w;
  vector<string>s(h);cin>>s;
  ll u=INF;
  ll d=-INF;
  ll l=INF;
  ll r=-INF;
  rep(i,h)rep(j,w){
    if(s.at(i).at(j)=='#'){
      u=min(u,i);
      d=max(d,i);
      l=min(l,j);
      r=max(r,j);
    }
  }
  reps(i,u,d+1){
    reps(j,l,r+1){
      cout<<s.at(i).at(j);
    }
    cout<<endl;
  }

  return 0;
}
