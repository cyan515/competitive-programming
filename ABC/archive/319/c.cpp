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
  vector c(3,vector<int>(3));
  rep(i,3) rep(j,3) cin>>c.at(i).at(j);
  vector<pair<int,int>> p;
  p.emplace_back(1,1);
  p.emplace_back(1,2);
  p.emplace_back(1,3);
  p.emplace_back(2,1);
  p.emplace_back(2,2);
  p.emplace_back(2,3);
  p.emplace_back(3,1);
  p.emplace_back(3,2);
  p.emplace_back(3,3);
  sort(all(p));
  int cnt = 0;
  do {
    vector t(3,vector<int>(3,-1));
    bool gakkari = false;
    rep(idx,p.size()) {
      int x = p.at(idx).first-1;
      int y = p.at(idx).second-1;
      t.at(x).at(y) = c.at(x).at(y);
      if(gakkari) break;
      rep(i,3) {
        set<int> st;
        bool same = false;
        rep(j,3) {
          if(t.at(i).at(j)!=-1) {
            if(st.count(t.at(i).at(j))) same = true;
            st.insert(t.at(i).at(j));
          }
        }
        if(same && st.size()==1) {
          gakkari = true;
        }
      }
      rep(j,3) {
        set<int> st;
        bool same = false;
        rep(i,3) {
          if(t.at(i).at(j)!=-1) {
            if(st.count(t.at(i).at(j))) same = true;
            st.insert(t.at(i).at(j));
          }
        }
        if(same && st.size()==1) {
          gakkari = true;
        }
      }
      
      rep(i,3) {
        set<int> st;
        bool same = false;
        rep(i,3) {
          if(t.at(i).at(i)!=-1) {
            if(st.count(t.at(i).at(i))) same = true;
            st.insert(t.at(i).at(i));
          }
        }
        if(same && st.size()==1) {
          gakkari = true;
        }
      }
      rep(i,3) {
        set<int> st;
        bool same = false;
        rep(i,3) {
          if(t.at(2-i).at(i)!=-1) {
            if(st.count(t.at(2-i).at(i))) same = true;
            st.insert(t.at(2-i).at(i));
          }
        }
        if(same && st.size()==1) {
          gakkari = true;
        }
      }
      
    }
    if(!gakkari) cnt++;
  } while(next_permutation(all(p)));
  
  long double ans = ((long double)cnt) / (long double)362880;
  cout << fixed << setprecision(10) << ans << endl;

  exit(0);
}
