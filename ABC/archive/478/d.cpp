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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m;cin>>n>>m;
  vector<ll>le(m),ri(m),x(m);
  rep(i,m)cin>>le.at(i)>>ri.at(i)>>x.at(i),le.at(i)--;
  // time,add,val
  priority_queue<tuple<int,bool,ll>,vector<tuple<int,bool,ll>>,greater<>>q;
  rep(i,m)q.push(tuple(le.at(i),true,x.at(i))),q.push(tuple(ri.at(i),false,x.at(i)));
  map<int,int>mp;
  vector<ll>ans(n);
  rep(i,n){
    while(q.size()&&get<0>(q.top())==i){
      auto [time,add,val]=q.top();q.pop();
      if(add)mp[val]++;
      else {
        auto it=mp.find(val);
        if((*it).second==1)mp.erase(it);
        else mp[val]--;
      }
    }
    ans.at(i)=mp.size();
  }
  rep(i,n){
    if(i)cout<<" ";
    cout<<ans.at(i);
  }
  cout<<endl;

  return 0;
}
