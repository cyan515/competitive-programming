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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,Q;cin>>n>>Q;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  vector<int> ord(n);
  rep(i,n) ord.at(i) = i;
  // https://qiita.com/yH3PO4/items/6bb19b10cecb28a7803c
  auto comp = [&](int i,int j) -> bool {
    bool s = y.at(i)>0||y.at(i)==0&&x.at(i)>0;
    bool t = y.at(j)>0||y.at(j)==0&&x.at(j)>0;
    if(s!=t) {
      return s>t;
    } else {
      return x.at(i)*y.at(j)<y.at(i)*x.at(j);
    }
  };
  auto same = [&](int i,int j) -> bool {
    bool s = y.at(i)>0||y.at(i)==0&&x.at(i)>0;
    bool t = y.at(j)>0||y.at(j)==0&&x.at(j)>0;
    if(s!=t) {
      return false;
    } else {
      return x.at(i)*y.at(j)==y.at(i)*x.at(j);
    }
  };
  sort(all(ord),comp);
  vector<int> rev(n);
  rep(i,n) rev.at(ord.at(i)) = i;
  vector<int> le(n),ri(n);
  rep(i,n) le.at(i) = rev.at(i), ri.at(i) = rev.at(i);
  rep(i,n-1) {
    int j = i+1;
    int ii = ord.at(i);
    int jj = ord.at(j);
    if(same(ii,jj)) {
      le.at(jj) = le.at(ii);
    }
  }
  for(int i=n-1;i>=1;i--) {
    int j = i-1;
    int ii = ord.at(i);
    int jj = ord.at(j);
    if(same(ii,jj)) {
      ri.at(jj) = ri.at(ii);
    }
  }
  while(Q--) {
    ll a,b;cin>>a>>b;
    a--;b--;
    if(comp(a,b) || same(a,b)) {
      cout << ri.at(b) - le.at(a) + 1 << endl;
    } else {
      ll s = n - le.at(a);
      ll t = ri.at(b) + 1;
      cout << s + t << endl;
    }
  }

  return 0;
}
