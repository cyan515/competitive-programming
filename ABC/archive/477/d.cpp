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
  string ans(n,'0');
  vector<pair<int,int>>qs(m);
  rep(i,m){
    int op,x;
    char c;
    cin>>op;
    if(op==1){
      cin>>x;
      qs.at(i)=pair(op,x);
    }else{
      cin>>c;
      qs.at(i)=pair(op,(int)c);
    }
  }
  vector<bool>tile(n,false);
  rep(i,m){
    if(qs.at(i).first==2)continue;
    qs.at(i).second--;
    tile.at(qs.at(i).second)=!tile.at(qs.at(i).second);
  }
  set<int>open;
  rep(i,n){
    if(tile.at(i))continue;
    open.insert(i);
  }
  reverse(all(qs));
  rep(i,m){
    auto [op,c]=qs.at(i);
    if(op==1){
      tile.at(c)=!tile.at(c);
      if(!tile.at(c)&&ans.at(c)=='0')open.insert(c);
      if(tile.at(c)&&open.count(c))open.erase(c);
    }else{
      for(auto ele:open){
        ans.at(ele)=(char)c;
      }
      open.clear();
    }
  }
  rep(i,ans.size()){
    if(ans.at(i)=='0')ans.at(i)='a';
  }
  cout<<ans<<endl;

  return 0;
}
