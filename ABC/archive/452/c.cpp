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
  int n;cin>>n;
  vector<int>a(n),b(n);
  rep(i,n)cin>>a.at(i)>>b.at(i),b.at(i)--;
  vector ex(11,vector(11,vector<bool>(26,false)));
  int m;cin>>m;
  vector<string>s(m);cin>>s;
  rep(j,m){
    rep(i,s.at(j).size()){
      ex.at(s.at(j).size()).at(i).at(s.at(j).at(i)-'a')=true;
    }
  }
  rep(j,m){
    if(s.at(j).size()!=n){
      cout<<No<<endl;
      continue;
    }
    bool ok=true;
    rep(i,n){
      ok&=ex.at(a.at(i)).at(b.at(i)).at(s.at(j).at(i)-'a');
    }
    cout<<(ok?Yes:No)<<endl;
  }

  return 0;
}
