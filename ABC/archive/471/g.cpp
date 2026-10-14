#include <bits/stdc++.h>
#include<atcoder/modint>
using mint=atcoder::modint998244353;
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
  int n;cin>>n;
  vector<ll>a(n);cin>>a;
  sort(all(a));
  stack<ll>neg;
  queue<ll>pos;
  rep(i,n){
    if(a.at(i)<0)neg.push(a.at(i));
    else pos.push(a.at(i));
  }
  ll cur=0;
  ll ans=0;
  while(pos.size()||neg.size()){
    ll d1=LINF;
    if(neg.size())d1=cur-neg.top();
    ll d2=LINF;
    if(pos.size())d2=pos.front()-cur;
    if(d1<=d2){
      ans+=d1;
      cur=neg.top();
      neg.pop();
    }else{
      ans+=d2;
      cur=pos.front();
      pos.pop();
    }
  }
  cout<<ans<<endl;

  return 0;
}
