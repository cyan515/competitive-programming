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
  vector<string> s(n);cin>>s;
  set<vector<string>> st;
  rep(i,n-m+1) rep(j,n-m+1) {
    vector<string> vec(m,string(m,'.'));
    rep(ii,m) rep(jj,m) {
      vec.at(ii).at(jj) = s.at(i+ii).at(j+jj);
    }
    st.insert(vec);
  }
  cout << st.size() << endl;

  return 0;
}
