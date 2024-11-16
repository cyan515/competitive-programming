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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<int> a(n),b(n-1);cin>>a>>b;
  sort(all(a));
  sort(all(b));
  int ok = INF;
  int ng = 0;
  while(abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    map<int,int> mp;
    mp[mid]++;
    rep(i,n-1) mp[b.at(i)]++;
    bool flg = true;
    rep(i,n) {
      auto it = mp.lower_bound(a.at(i));
      if(it==mp.end()) {
        flg = false;
        break;
      }
      auto& [k,v] = *it;
      if(v==1) {
        mp.erase(it);
      } else {
        v--;
      }
    }
    if(flg) ok = mid;
    else ng = mid;
  }
  if(ok==INF) ok = -1;
  cout << ok << endl;

  return 0;
}
