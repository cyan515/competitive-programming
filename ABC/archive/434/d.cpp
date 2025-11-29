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
  int m = 2000;
  vector a(m+1,vector<int>(m+1,0));
  vector b(m+1,vector<ll>(m+1,0));
  vector<int> us(n),ds(n),ls(n),rs(n);
  rep(i,n) {
    int u,d,l,r;cin>>u>>d>>l>>r;l--;u--;
    us.at(i)=u;ds.at(i)=d;ls.at(i)=l,rs.at(i)=r;
    a.at(u).at(l)++;
    a.at(u).at(r)--;
    a.at(d).at(l)--;
    a.at(d).at(r)++;
    b.at(u).at(l)+=i+1;
    b.at(u).at(r)-=i+1;
    b.at(d).at(l)-=i+1;
    b.at(d).at(r)+=i+1;
  }
  
  rep(i,m) rep(j,m) {
    if(i) a.at(i).at(j) += a.at(i-1).at(j), b.at(i).at(j) += b.at(i-1).at(j);
    if(j) a.at(i).at(j) += a.at(i).at(j-1), b.at(i).at(j) += b.at(i).at(j-1);
    if(i) if(j) a.at(i).at(j) -= a.at(i-1).at(j-1), b.at(i).at(j) -= b.at(i-1).at(j-1);
  }
  int cnt = 0;
  vector<int> ans(n,0);
  rep(i,m) rep(j,m) {
    if(a.at(i).at(j)==0) cnt++;
    else if(a.at(i).at(j)==1) {
      ans.at(b.at(i).at(j)-1)++;
    }
  }
  rep(i,n) {
    cout<<cnt+ans.at(i)<<endl;
  }

  return 0;
}
