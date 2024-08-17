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
  int Q;cin>>Q;
  map<int,int> mp;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int x;cin>>x;
      mp[x]++;
    } else if(t==2) {
      int x;cin>>x;
      mp[x]--;
      if(mp[x]==0) mp.erase(mp.find(x));
    } else {
      cout << mp.size() << endl;
    }
  }

  return 0;
}
