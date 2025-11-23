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
  string s;cin>>s;
  sort(all(s));
  int z = 0;
  {
    string t = "";
    rep(i,s.size()) {
      if(s.at(i)=='0')continue;
      t.push_back(s.at(i));
    }
    for(char c : s) {
      if(c=='0') z++;
    }
    swap(s,t);
  }
  cout<<s.front();
  rep(i,z) cout<<"0";
  reps(i,1,s.size()) cout<<s.at(i);
  cout<<endl;

  return 0;
}
