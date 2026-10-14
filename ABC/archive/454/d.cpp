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
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    string u="";
    rep(i,n){
      u.push_back(s.at(i));
      if(u.back()==')'){
        if(u.size()>=4&&u.substr(u.size()-4,u.size())=="(xx)"){
          rep(_,4)u.pop_back();
          rep(_,2)u.push_back('x');
        }
      }
    }
    string v="";
    rep(i,m){
      v.push_back(t.at(i));
      if(v.back()==')'){
        if(v.size()>=4&&v.substr(v.size()-4,v.size())=="(xx)"){
          rep(_,4)v.pop_back();
          rep(_,2)v.push_back('x');
        }
      }
    }
    cout<<(u==v?Yes:No)<<endl;
  }

  return 0;
}
