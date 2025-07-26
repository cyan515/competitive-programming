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
  int n,k,x;cin>>n>>k>>x;
  vector<string> s(n);cin>>s;
  vector<string> cur;
  vector<string> vec;
  auto f = [&](auto self,int v) -> void {
    if(v==k) {
      string xx = "";
      for(auto& ele : cur) xx += ele;
      vec.push_back(xx);
      return;
    }
    rep(i,n) {
      cur.push_back(s.at(i));
      self(self,v+1);
      cur.pop_back();
    }
  };
  f(f,0);
  sort(all(vec));
  cout << vec.at(x-1) << endl;

  return 0;
}
