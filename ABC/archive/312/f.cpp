#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n,m;cin>>n>>m;
  vector<ll> a;
  vector<ll> b;
  vector<ll> c;
  rep(i,n) {
    ll t,x;cin>>t>>x;
    if(t==0) a.push_back(x);
    else if(t==1) b.push_back(x);
    else c.push_back(x);
  }
  int an = a.size();
  int bn = b.size();
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  sort(c.rbegin(),c.rend());
  rep(i,an-1) a.at(i+1) += a.at(i);
  rep(i,bn-1) b.at(i+1) += b.at(i);
  a.insert(a.begin(),0);
  b.insert(b.begin(),0);
  an++;bn++;
  vector<ll> bc(m+1);
  int ccnt = 0;
  int bi = 0;
  int ci = 0;
  ll sat = 0;
  reps(i,1,m+1) {
    if(ci==c.size() && (bi==b.size() || bi==ccnt)) {
      bc.at(i) = sat;
      continue;
    }
    if(bi==ccnt) ccnt += c.at(ci++);
    else sat = b.at(min(++bi,bn-1));
    bc.at(i) = sat;
  }
  ll ans = 0;
  rep(i,min(m+1,an)) {
    ll tmp = a.at(i)+bc.at(max(0,m-i));
    ans = max(ans,tmp);
  }
  cout << ans << endl;

  exit(0);
}
