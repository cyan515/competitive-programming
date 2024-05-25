#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector<pair<int,int>> a(n+m);
  rep(i,n) {
    cin>>a.at(i).first;
    a.at(i).second = 1;
  }
  rep(i,m) {
    cin>>a.at(n+i).first;
    a.at(n+i).second = 0;
  }
  sort(all(a));
  bool flg = false;
  rep(i,n+m-1) {
    if(a.at(i).second==1&&a.at(i).second == a.at(i+1).second) flg = true;
  }
  YN(flg);
  

  return 0;
}
