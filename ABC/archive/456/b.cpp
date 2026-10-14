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
  vector<int>a(6),b(6),c(6);
  cin>>a>>b>>c;
  int cnt=0;
  rep(i,6)rep(j,6)rep(k,6){
    vector<int>x={a.at(i),b.at(j),c.at(k)};
    sort(all(x));
    if(x.at(0)==4&&x.at(1)==5&&x.at(2)==6)cnt++;
  }
  cout<<fixed<<setprecision(20);
  cout<<(long double)cnt/(long double)(6*6*6)<<endl;
  
  return 0;
}
