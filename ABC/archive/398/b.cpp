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
  int n = 7;
  vector<int> a(n);cin>>a;
  auto f = [](map<int,int>& mp) -> bool {
    if(mp.size()!=2) {
      return false;
    }
    set<int> st;
    for(auto [k,v] : mp) {
      st.insert(v);
    }
    if(st.count(2)&&st.count(3)) return true;
    else return false;
  };
  vector<int> sel = {0,1,2,3,4,5,6};
  bool ans = false;
  do {
    map<int,int> mp;
    rep(i,5) {
      mp[a.at(sel.at(i))]++;
      ans |= f(mp);
    }
  } while(next_permutation(all(sel)));
  cout << (ans?Yes:No) << endl;

  return 0;
}
