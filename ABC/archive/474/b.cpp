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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  vector<int>a(n);cin>>a;
  while(a.size()%10)a.push_back(INF);
  for(int i=0;i<n;i+=10){
    sort(a.begin()+i,a.begin()+i+10);
  }
  auto b=a;
  sort(all(b));
  cout<<(a==b?Yes:No)<<endl;

  return 0;
}
