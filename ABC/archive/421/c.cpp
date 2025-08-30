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
  string s;cin>>s;
  vector<int> a,b;
  rep(i,2*n) {
    if(s.at(i)=='A') a.push_back(i);
    else b.push_back(i);
  }
  ll ans = LINF;
  ll cnt = 0;
  rep(i,n) {
    int ai = 2*i;
    int bi = 2*i+1;
    cnt += abs(a.at(i)-ai);
    cnt += abs(b.at(i)-bi);
  }
  cnt /= 2;
  ans = min(ans,cnt);
  cnt = 0;
  rep(i,n) {
    int ai = 2*i+1;
    int bi = 2*i;
    cnt += abs(a.at(i)-ai);
    cnt += abs(b.at(i)-bi);
  }
  cnt /= 2;
  ans = min(ans,cnt);
  cout << ans << endl;

  return 0;
}
