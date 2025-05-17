#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
  int h,w,n;cin>>h>>w>>n;
  vector<int> x_cnt(h+1,0),y_cnt(w+1,0);
  vector x(h+1,vector<int>()), y(w+1,vector<int>());
  rep(i,n) {
    int a,b;cin>>a>>b;
    x_cnt.at(a)++;
    y_cnt.at(b)++;
    x.at(a).push_back(b);
    y.at(b).push_back(a);
  }
  set<pair<int,int>> st;
  int Q;cin>>Q;
  while(Q--) {
    int t,p;cin>>t>>p;
    if(t==1) {
      cout << x_cnt.at(p) << endl;
      if(x_cnt.at(p)==0) continue;
      x_cnt.at(p) = 0;
      for(auto ele : x.at(p)) {
        if(st.count(pair(p,ele))) continue;
        y_cnt.at(ele)--;
        st.insert(pair(p,ele));
      }
    } else {
      cout << y_cnt.at(p) << endl;
      if(y_cnt.at(p)==0) continue;
      y_cnt.at(p) = 0;
      for(auto ele : y.at(p)) {
        if(st.count(pair(ele,p))) continue;
        x_cnt.at(ele)--;
        st.insert(pair(ele,p));
      }
    }
  }

  return 0;
}
