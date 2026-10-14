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
  ll n,Q;cin>>n>>Q;
  vector<ll>a(n);cin>>a;
  set<pair<ll,int>>st;
  rep(i,n)st.insert(pair(a.at(i),i));
  while(Q--){
    ll k;cin>>k;
    vector<ll>b(k);cin>>b;
    rep(i,k)b.at(i)--;
    rep(i,k)st.erase(pair(a.at(b.at(i)),b.at(i)));
    cout<<(*st.begin()).first<<endl;
    rep(i,k)st.insert(pair(a.at(b.at(i)),b.at(i)));
  }

  return 0;
}
