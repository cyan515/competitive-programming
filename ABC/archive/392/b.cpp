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
  int n,m;cin>>n>>m;
  vector<int> a(m);cin>>a;
  set<int> st;
  rep(i,n) st.insert(i+1);
  rep(i,m) {
    auto it = st.find(a.at(i));
    if(it==st.end()) continue;
    st.erase(it);
  }
  cout << st.size() << endl;
  int cnt = 0;
  for(auto ele : st) {
    cout << ele;
    cnt++;
    if(cnt<st.size()) cout << " ";
  }
  cout << endl;

  return 0;
}
