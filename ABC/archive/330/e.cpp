#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n;cin>>n;int Q;cin>>Q;
  vector<int> a(n);
  multiset<int> st;
  set<int> ab;
  rep(i,n) cin>>a.at(i),st.insert(a.at(i));
  rep(i,n+1) ab.insert(i);
  rep(i,n) {
    auto it = ab.find(a.at(i));
    if(it!=ab.end()) ab.erase(it);
  }
  while(Q--) {
    int i,x;cin>>i>>x;i--;
    int tmp = a.at(i);
    a.at(i) = x;
    st.erase(st.find(tmp));
    st.insert(x);
    if(st.find(tmp)==st.end()) ab.insert(tmp);
    auto it = ab.find(x);
    if(it!=ab.end()) ab.erase(it);
    int ans = *ab.begin();
    cout << ans << endl;
  }

  exit(0);
}
