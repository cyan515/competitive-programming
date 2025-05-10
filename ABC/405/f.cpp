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
  int n;cin>>n>>n;
  vector<tuple<int,int,int>> vec;
  rep(i,n) {
    int a,b;cin>>a>>b;a--;
    vec.push_back({a,b,-1});
  }
  int m;cin>>m;
  rep(i,m) {
    int c,d;cin>>c>>d;c--;
    vec.push_back({c,d,i});
  }
  vector<int> ans(m,0);
  int ma = 2000010;
  fenwick_tree<int> ft(ma);
  sort(all(vec));
  priority_queue<int,vector<int>,greater<>> q;
  rep(i,vec.size()) {
    auto [a,b,idx] = vec.at(i);
    while(q.size()&&q.top()<=a) q.pop();
    if(idx==-1) {
      ft.add(b,1);
      q.push(b);
    } else {
      ans.at(idx) += q.size() - ft.sum(b,ma);
    }
  }
  rep(i,vec.size()) {
    auto [a,b,idx] = vec.at(i);
    vec.at(i) = {ma-5-b,ma-5-a,idx};
  }
  fenwick_tree<int> gt(ma);
  sort(all(vec));
  while(q.size()) q.pop();
  rep(i,vec.size()) {
    auto [a,b,idx] = vec.at(i);
    while(q.size()&&q.top()<=a) q.pop();
    if(idx==-1) {
      gt.add(b,1);
      q.push(b);
    } else {
      ans.at(idx) += q.size() - gt.sum(b,ma);
    }
  }
  rep(i,m) cout << ans.at(i) << endl;

  return 0;
}
