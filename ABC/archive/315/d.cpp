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
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int h,w;cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s.at(i);
  vector hcnt(h,map<char,int>());
  vector wcnt(w,map<char,int>());
  vector<bool> hrm(h,false);
  vector<bool> wrm(w,false);
  int rmcnt = 0;
  rep(i,h) rep(j,w) hcnt.at(i)[s.at(i).at(j)]++;
  rep(j,w) rep(i,h) wcnt.at(j)[s.at(i).at(j)]++;
  rep(i,h) {
    set<char> st;
    int tmp = 0;
    rep(j,w) if(!wrm.at(j)) st.insert(s.at(i).at(j)),tmp++;
    if(st.size()==1 && tmp>=2) {
      hrm.at(i) = true;
      rmcnt++;
      char ch = *st.begin();
      rep(j,w) {
        wcnt.at(j)[ch]--;
      }
    }
    rep(j,w) {
      int cnt = 0;
      int sum = 0;
      rep(k,26) {
        if(wcnt.at(j)['a'+k]>0) cnt++,sum+=wcnt.at(j)['a'+k];
      }
      if((cnt==1&&(sum>=2||(i==h-1&&s.at(i).at(j)==s.at(i-1).at(j))))) wrm.at(j) = true;
    }
  }
  int x=0,y=0;
  rep(i,h) if(!hrm.at(i)) x++;
  rep(i,w) if(!wrm.at(i)) y++;
  cout << x * y << endl;
  
  exit(0);
}
