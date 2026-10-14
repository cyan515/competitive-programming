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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,k;cin>>n>>k;
  vector<ll>a(n);cin>>a;
  vector<ll>sum(n+1,0);
  rep(i,n){
    sum.at(i+1)+=(a.at(i)%k+sum.at(i))%k;
  }
  int ans=0;
  int last=-1;
  map<int,int>mp;
  mp[0]++;
  reps(i,1,n+1){
    auto it=mp.find(sum.at(i));
    if(it!=mp.end()){
      if((*it).second>=last){
        last=i;
        ans++;
      }
    }
    mp[sum.at(i)]=i;
  }
  cout<<ans<<endl;

  return 0;
}
