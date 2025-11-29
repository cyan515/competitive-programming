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
  int n,m;cin>>n>>m;
  vector<int> a(n),b(n);
  rep(i,n)cin>>a.at(i)>>b.at(i);
  vector<int> cnt(m,0),sum(m,0);
  rep(i,n) {
    a.at(i)--;
    cnt.at(a.at(i))++;
    sum.at(a.at(i)) += b.at(i);
  }
  cout<<fixed<<setprecision(20);
  rep(i,m) {
    cout<<(long double)sum.at(i)/(long double)cnt.at(i)<<endl;
  }

  return 0;
}
