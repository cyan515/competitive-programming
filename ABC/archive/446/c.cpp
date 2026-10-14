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
  int T;cin>>T;
  while(T--) {
    ll n,d;cin>>n>>d;
    vector<ll>a(n),b(n);cin>>a>>b;
    // day,cnt
    queue<pair<ll,ll>>q;
    rep(i,n){
      q.push(pair(i,a.at(i)));
      while(b.at(i)){
        int use = min(b.at(i),q.front().second);
        b.at(i)-=use;
        q.front().second-=use;
        if(q.front().second==0)q.pop();
      }
      while(q.size()&&q.front().first<=i-d) q.pop();
    }
    ll ans=0;
    while(q.size()){
      ans+=q.front().second;
      q.pop();
    }
    cout<<ans<<endl;
  }

  return 0;
}
