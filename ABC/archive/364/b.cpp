#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

int main() {
  int h,w;cin>>h>>w;
  int si,sj;cin>>si>>sj;si--;sj--;
  vector<string> s(h);cin>>s;
  string x;cin>>x;
  int n = x.size();
  auto can = [&](unsigned x,unsigned y) -> bool {
    return x<h&&y<w&&s.at(x).at(y)=='.';
  };
  rep(i,n) {
    int di,dj;
    if(x.at(i)=='L') {
      di = 0;
      dj = -1;
    }
    if(x.at(i)=='R') {
      di = 0;
      dj = 1;
    }
    if(x.at(i)=='U') {
      di = -1;
      dj = 0;
    }
    if(x.at(i)=='D') {
      di = 1;
      dj = 0;
    }
    if(!can(si+di,sj+dj)) continue;
    si += di;
    sj += dj;
  }
  si++;sj++;
  cout << si << " " << sj << endl;

  return 0;
}
