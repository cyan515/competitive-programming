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
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> x;
  for(auto e : a) {
    x.push_back(e);
    if(x.size()>=4 && *x.rbegin()==*(x.rbegin()+1) && *(x.rbegin()+1)==*(x.rbegin()+2) && *(x.rbegin()+2)==*(x.rbegin()+3)) {
      rep(_,4) x.pop_back();
    }
  }
  cout<<x.size()<<endl;

  return 0;
}
