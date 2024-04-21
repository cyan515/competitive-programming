#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<int> a(n);cin>>a;
  vector<int> idx(n);
  rep(i,n) {
    a.at(i)--;
    idx.at(a.at(i)) = i;
  }
  vector<pair<int,int>> ans;
  rep(i,n-1) {
    if(idx.at(i)==i) continue;
    ans.push_back(pair(i,idx.at(i)));
    int tmp = idx.at(i);
    int tmp2 = idx.at(a.at(i));
    swap(idx.at(i),idx.at(a.at(i)));
    swap(a.at(tmp),a.at(tmp2));
  }
  cout << ans.size() << endl;
  for(auto [x,y] : ans) {
    cout << x+1 << " " << y+1 << endl;
  }

  return 0;
}
