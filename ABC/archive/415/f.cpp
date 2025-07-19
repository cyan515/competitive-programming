#include <bits/stdc++.h>
#include <atcoder/segtree>
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
using S = tuple<int,char,int,char,int,bool>;
S op(S a,S b) {
  auto [alen,alc,allen,arc,arlen,aall] = a;
  auto [blen,blc,bllen,brc,brlen,ball] = b;
  if(alc=='.') return b;
  if(blc=='.') return a;
  int len,llen,rlen;
  llen = allen;
  if(aall&&arc==blc) {
    llen += bllen;
  }
  rlen = brlen;
  if(ball&&arc==blc) {
    rlen += arlen;
  }
  len = max({llen,rlen,alen,blen});
  if(arc==blc) len = max(len,arlen+bllen);
  char lc = alc, rc = brc;
  
  return tuple(len,lc,llen,rc,rlen,aall&&ball&&arc==blc);
}
S e() {
  return tuple(0,'.',0,'.',0,false);
}

int main() {
  int n;cin>>n;
  int Q;cin>>Q;
  string s;cin>>s;
  atcoder::segtree<S,op,e> seg(n);
  rep(i,n) {
    seg.set(i,tuple(1,s.at(i),1,s.at(i),1,true));
  }
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int idx;cin>>idx;idx--;
      char c;cin>>c;
      seg.set(idx,tuple(1,c,1,c,1,true));
      s.at(idx) = c;
    } else {
      int l,r;cin>>l>>r;l--;
      auto ans = seg.prod(l,r);
      cout << get<0>(ans) << endl;
      
      // auto [a,b,cc,d,e,f] = seg.prod(l,r);
      // cout << a << " " << b << " " << cc << " " << d << " " << e << " " << f;
      // cout<<endl;
    }
  }

  return 0;
}
