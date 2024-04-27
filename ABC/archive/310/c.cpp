#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  rep(i,n) {
    string t = s.at(i);
    reverse(s.at(i).begin(),s.at(i).end());
    if(s.at(i)<t) s.at(i)=t;
  }
  set<string> st;
  rep(i,n) st.insert(s.at(i));
  cout << st.size() << endl;

  exit(0);
}
