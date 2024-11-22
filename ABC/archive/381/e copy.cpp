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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// val, idx
using S = vector<pair<int,int>>;
S op(S a,S b) {
  auto x = a;
  x.insert(x.end(),all(b));
  sort(all(x));
  if(x.size()>3) x.resize(3);
  return x;
}

S e() {
  return {};
}

vector<tuple<char, int, int>> run_length(const string& str) {
  int n = (int)str.size();
  vector<tuple<char, int, int>> ret;
  for (int l = 0; l < n;) {
    int r = l + 1;
    for (; r < n && str[l] == str[r]; r++) {};
    ret.push_back({str[l], r - l, l});
    l = r;
  }
  return ret;
}

int main() {
  int n,Q;cin>>n>>Q;
  string s;cin>>s;
  auto x = run_length(s);
  int m = x.size();
  segtree<S,op,e> st(n);
  reps(i,1,m-1) {
    auto [c,len,idx] = x.at(i);
    
    if(c=='/'&&len==1 && get<0>(x.at(i-1))=='1' && get<0>(x.at(i+1))=='2') {
      st.set(idx,{pair(1+2*min(get<2>(x.at(i-1)),get<2>(x.at(i+1))),idx)});
    }
  }
  while(Q--) {
    int l,r;cin>>l>>r;l--;
    auto res = st.prod(l,r);
    rep(i,res.size()) {
      auto [len,idx] = res.at(i);
      if(idx-len<l) res.at(i).first = idx-l;
      if(idx+len>=r) res.at(i).first = r-idx-1;
    }
    int ans = 0;
    rep(i,res.size()) {
      if(res.at(i).first == 0) continue;
      chmax(ans,res.at(i).first*2+1);
    }
    cout << ans << endl;
  }

  return 0;
}
