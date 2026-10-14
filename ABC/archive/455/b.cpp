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
  int h,w;cin>>h>>w;vector<string>s(h);cin>>s;
  int ans=0;
  rep(ai,h)rep(aj,w)reps(bi,ai,h)reps(bj,aj,w){
    bool ok=true;
    reps(ci,ai,bi+1)reps(cj,aj,bj+1){
      ok&=s.at(ci).at(cj)==s.at(bi-ci+ai).at(bj-cj+aj);
    }
    ans+=!!(ok);
  }
  cout<<ans<<endl;

  return 0;
}
