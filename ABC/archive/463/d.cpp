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
  ll n,k;cin>>n>>k;
  vector<ll>l(n),r(n);
  rep(i,n)cin>>l.at(i)>>r.at(i);
  vector<int>ord(n);
  rep(i,n)ord.at(i)=i;
  sort(all(ord),[&](int i,int j)->bool{
    if(r.at(i)!=r.at(j))return r.at(i)<r.at(j);
    else return l.at(i)<l.at(j);
  });
  ll ok=-1;
  ll ng=INF;
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    ll cnt=0;
    ll cur=-INF;
    for(auto i:ord){
      if(cur+mid<=l.at(i)){
        cnt++;
        cur=r.at(i);
      }
    }
    if(cnt>=k)ok=mid;
    else ng=mid;
  }
  if(ok==0)ok=-1;
  cout<<ok<<endl;

  return 0;
}
