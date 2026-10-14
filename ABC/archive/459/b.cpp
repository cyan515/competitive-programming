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
  vector<string>s(n);cin>>s;
  rep(i,n){
    int x=(s.at(i).front()-'a')/3+2;
    if(s.at(i).front()>='s'){
      if(s.at(i).front()=='s')x=7;
      
      if(s.at(i).front()=='t')x=8;
      if(s.at(i).front()=='u')x=8;
      if(s.at(i).front()=='v')x=8;
      
      if(s.at(i).front()=='w')x=9;
      if(s.at(i).front()=='x')x=9;
      if(s.at(i).front()=='y')x=9;
      if(s.at(i).front()=='z')x=9;
    }
    cout<<x;
  }
  cout<<endl;

  return 0;
}
