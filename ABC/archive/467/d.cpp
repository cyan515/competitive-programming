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
  int T;cin>>T;
  while(T--){
    ll x1,y1,x2,y2,x3,y3,x4,y4;cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    __int128 a1,b1,c1,a2,b2,c2;
    a1=(__int128)2*(x2-x1);
    b1=(__int128)2*(y2-y1);
    c1=-(x2*x2-x1*x1+y2*y2-y1*y1);
    a2=(__int128)2*(x4-x3);
    b2=(__int128)2*(y4-y3);
    c2=-(x4*x4-x3*x3+y4*y4-y3*y3);
    //https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q10245840105
    __int128 d=a1*b2-a2*b1;
    if(d!=0)cout<<Yes<<endl;
    else {
      if(a1*c2==a2*c1&&b1*c2==b2*c1)cout<<Yes<<endl;
      else cout<<No<<endl;
    }
  }

  return 0;
}
