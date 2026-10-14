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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n;cin>>n;
  priority_queue<ll,vector<ll>,greater<>>q;
  set<ll>st;
  rep(i,n){
    if((1LL<<i)>1000000000LL)break;
    q.push(1LL<<i);
    st.insert(1LL<<i);
  }
  rep(ii,n){
    ll cur=q.top();
    rep(i,n){
      if((1LL<<i)>1000000000LL)break;
      ll x=1LL;
      ll sz=to_string((1LL<<i)).size();
      while(sz--)x*=10LL;
      x*=cur;
      x+=(1LL<<i);
      if(x>1000000000LL)continue;
      if(st.count(x))continue;
      st.insert(x);
      q.push(x);
      if(q.size()>=1199898)break;
    }
    if(ii<n-1)q.pop();
  }
  cout<<q.top()<<endl;

  return 0;
}
