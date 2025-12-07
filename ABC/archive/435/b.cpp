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
  vector<int>a(n);cin>>a;
  int ans = 0;
  rep(l,n) reps(r,l+1,n+1) {
    bool ok = true;
    int sum = 0;
    reps(i,l,r) {
      sum += a.at(i);
    }
    reps(i,l,r) {
      ok &= (sum%a.at(i)!=0);
    }
    ans += !!ok;
  }
  cout<<ans<<endl;

  return 0;
}
