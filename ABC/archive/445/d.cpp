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
  int n,rh,rw;cin>>rh>>rw>>n;
  vector<int> a(n),b(n);
  rep(i,n)cin>>a.at(i)>>b.at(i);
  vector<bool> used(n,false);
  vector<pair<int,int>> ans(n);
  vector<int> ao(n),bo(n);
  rep(i,n) {
    ao.at(i)=i;
    bo.at(i)=i;
  }
  sort(all(ao),[&](int i,int j)->bool{
    return a.at(i)>a.at(j);
  });
  sort(all(bo),[&](int i,int j)->bool{
    return b.at(i)>b.at(j);
  });
  int ai = 0;
  int bi = 0;
  while(ai<n||bi<n) {
    while(ai<n&&used.at(ao.at(ai)))ai++;
    if(ai<n) {
      int i = ao.at(ai);
      int h = a.at(i);
      int w = b.at(i);
      if(h==rh) {
        rw -= w;
        ans.at(i) = pair(1,rw+1);
        ai++;
        used.at(i) = true;
      }
    }
    while(bi<n&&used.at(bo.at(bi)))bi++;
    if(bi<n) {
      int i = bo.at(bi);
      int h = a.at(i);
      int w = b.at(i);
      if(w==rw) {
        rh -= h;
        ans.at(i) = pair(rh+1,1);
        bi++;
        used.at(i) = true;
      }
    }
  }
  rep(i,n) {
    auto [x,y] = ans.at(i);
    cout<<x<<" "<<y<<endl;
  }

  return 0;
}
