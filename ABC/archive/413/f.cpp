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
  int n,k;cin>>n>>k;
  vector<int> a(n);cin>>a;
  set<int> st;
  rep(i,n) st.insert(a.at(i));
  int cnt = -1;
  int ans = 0;
  int cur = -1;
  for(auto ele : st) {
    chmax(ans,cnt);
    if(cur==-1) {
      cur = ele;
      cnt = 1;
    } else {
      if(cur+1==ele) {
        cur = ele;
        cnt++;
      } else {
        chmax(ans,cnt);
        cnt = 0;
        cur=-1;
      }
    }
    chmax(ans,cnt);
  }
  if(ans>=k) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
