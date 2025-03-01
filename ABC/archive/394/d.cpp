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
  string s;cin>>s;
  int n = s.size();
  vector<char> vec;
  rep(i,n) {
    vec.push_back(s.at(i));
    while(vec.size()>=2&&((vec.at(vec.size()-2)=='<'&&vec.at(vec.size()-1)=='>')
          || (vec.at(vec.size()-2)=='['&&vec.at(vec.size()-1)==']')
          || (vec.at(vec.size()-2)=='('&&vec.at(vec.size()-1)==')')
        )) {
      vec.pop_back();vec.pop_back();
    }
  }
  if(vec.size()==0) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
