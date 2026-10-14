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
  string s;cin>>s;
  int n=s.size();
  queue<int>a,b,c;
  rep(i,n){
    if(s.at(i)=='A')a.push(i);
    if(s.at(i)=='B')b.push(i);
    if(s.at(i)=='C')c.push(i);
  }
  int ans=0;
  while(!a.empty()&&!b.empty()&&!c.empty()){
    int bi=b.front();b.pop();
    if(a.front()>bi)continue;
    while(c.size()&&c.front()<bi)c.pop();
    if(c.empty())break;
    a.pop();
    c.pop();
    ans++;
  }
  cout<<ans<<endl;

  return 0;
}
