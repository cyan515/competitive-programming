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
  ll n,k;cin>>n>>k;
  vector<vector<int>>ans;
  vector<int>cur(n,0);
  cur.at(0)=k;
  auto dfs=[&](auto self,int idx)->void{
    if(idx==n){
      ans.push_back(cur);
      return;
    }
    ll tmp=cur.front();
    self(self,idx+1);
    while(cur.front()>=idx+1){
      cur.front()-=idx+1;
      cur.at(idx)++;
      self(self,idx+1);
    }
    cur.front()=tmp;
    cur.at(idx)=0;
  };
  dfs(dfs,1);
  sort(all(ans));
  rep(i,ans.size()){
    rep(j,ans.at(i).size()){
      if(j)cout<<" ";
      cout<<ans.at(i).at(j);
    }
    cout<<endl;
  }

  return 0;
}
