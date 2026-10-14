#include <bits/stdc++.h>
using namespace std;
#include <atcoder/fenwicktree>
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
  ll n,Q;cin>>n>>Q;
  atcoder::fenwick_tree<ll>ft(300010);
  ft.add(0,n);
  ll mi=0;
  vector<ll>vec(n,0);
  while(Q--){
    int op;cin>>op;
    if(op==1){
      ll x;cin>>x;x--;
      ft.add(vec.at(x),-1);
      if(vec.at(x)==mi&&ft.sum(vec.at(x),vec.at(x)+1)==0)mi++;
      vec.at(x)++;
      ft.add(vec.at(x),1);
    }else{
      ll y;cin>>y;
      if(y+mi>=300010){
        cout<<0<<endl;
        continue;
      }
      ll ans=ft.sum(y+mi,300010);
      cout<<ans<<endl;
    }
  }

  return 0;
}
