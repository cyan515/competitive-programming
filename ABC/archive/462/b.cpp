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
  vector a(n,vector<int>());
  vector ans(n,vector<int>());
  rep(i,n){
    int k;cin>>k;a.at(i).resize(k);cin>>a.at(i);
    for(auto ele:a.at(i)){
      ans.at(ele-1).push_back(i+1);
    }
  }
  rep(i,n){
    cout<<ans.at(i).size();
    sort(all(ans.at(i)));
    rep(j,ans.at(i).size()){
      cout<<" ";
      cout<<ans.at(i).at(j);
    }cout<<endl;
  }

  return 0;
}
