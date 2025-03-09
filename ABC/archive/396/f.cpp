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
using S = pair<ll,ll>;
using F = ll;
S op(S a,S b) {
  auto [x,y] = a;
  auto [s,t] = b;
  return pair(x+s,y+t);
}
S e() {
  return pair(0LL,0LL);
}
S mapping(F f,S s) {
  return pair(s.first+f*s.second,s.second);
}
F comp(F f,F g) {
  return f+g;
}
F id() {
  return 0LL;
}

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(n);cin>>a;
  vector x(m,vector<int>());
  rep(i,n) {
    if(a.at(i)%m==0) continue;
    x.at(m-a.at(i)%m).push_back(i);
  }
  lazy_segtree<S,op,e,F,mapping,comp,id> ri(n),le(n);
  ll cur = 0;
  {
    fenwick_tree<ll> ft(m);
    rep(i,n) {
      cur += ft.sum(a.at(i)%m+1,m);
      le.set(i,pair(ft.sum(a.at(i)%m+1,m),1));
      ft.add(a.at(i)%m,1);
    }
  }
  // {
  //   ll curr = 0;
  //   fenwick_tree<ll> ft(m);
  //   for(int i=n-1;i>=0;i--) {
  //     curr += ft.sum(0,a.at(i)%m);
  //     ri.set(i,ft.sum(0,a.at(i)%m));
  //     ft.add(a.at(i)%m,1);
  //   }
  // }
  vector<int> cnt(n,0);
  {
    vector<int> temp(m,0);
    rep(i,n) {
      cnt.at(i) = temp.at(a.at(i));
      temp.at(a.at(i))++;
    }
  }
  // rep(i,n) cout << le.get(i) << " ";
  // cout << endl;
  rep(i,m) {
    for(auto ele : x.at(i)) {
      le.set(ele,pair(ele-cnt.at(ele),1));
      le.apply(ele+1,n,-1);
    }
    cout << le.all_prod().first << endl;
    // rep(i,n) cout << le.get(i) << " ";
    // cout << endl;
  }

  return 0;
}
