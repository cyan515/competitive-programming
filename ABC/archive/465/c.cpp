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
  ll n;cin>>n;
  string s;cin>>s;
  queue<int>q;
  stack<int>st;
  bool flg=false;
  for(int i=n-1;i>=0;i--){
    if(s.at(i)=='o'){
      flg=!flg;
    }else{
      
    }
    if(flg){
      q.push(i+1);
    }else{
      st.push(i+1);
    }
  }
  vector<int>ans;
  while(q.size()){
    ans.push_back(q.front());q.pop();
  }
  while(st.size()){
    ans.push_back(st.top());st.pop();
  }
  rep(i,n){
    if(i)cout<<" ";
    cout<<ans.at(i);
  }
  cout<<endl;

  return 0;
}
