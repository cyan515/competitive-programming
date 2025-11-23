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
  int T;cin>>T;
  while(T--) {
    ll n,m;cin>>n>>m;
    vector<ll> x(n),y(m);cin>>x>>y;
    rep(i,n) x.at(i)--;
    rep(j,m) y.at(j)--;
    bool ok = true;
    {
      set<int> st;
      rep(i,n) {
        ok &= st.count(x.at(i))==0;
        st.insert(x.at(i));
      }
    }
    {
      set<int> st;
      rep(j,m) {
        ok &= st.count(y.at(j))==0;
        st.insert(y.at(j));
      }
    }
    if(!ok) {
      cout << No << endl;continue;
    }
    map<int,int> xmp,ymp;
    rep(i,n) xmp[x.at(i)] = i;
    rep(j,m) ymp[y.at(j)] = j;
    vector ans(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    vector<int> xopen,yopen;
    for(int a=n*m-1;a>=0;a--) {
      auto xit = xmp.find(a);
      auto yit = ymp.find(a);
      if(xit!=xmp.end()&&yit!=ymp.end()) {// both found
        int i = (*xit).second;
        int j = (*yit).second;
        if(ans.at(i).at(j)!=-1) {
          ok = false;break;
        }
        ans.at(i).at(j) = a;
        for(auto jj : yopen) q.push(pair(i,jj));
        for(auto ii : xopen) q.push(pair(ii,j));
        xopen.push_back(i);
        yopen.push_back(j);
      } else if(xit!=xmp.end()) {// only x
        int i = (*xit).second;
        if(!yopen.size()) {
          ok = false;break;
        }
        int j = yopen.front();
        if(ans.at(i).at(j)!=-1) {
          ok = false;break;
        }
        ans.at(i).at(j) = a;
        for(auto jj : yopen) {
          if(jj==j) continue;
          q.push(pair(i,jj));
        }
        xopen.push_back(i);
      } else if(yit!=ymp.end()) {// only y
        int j = (*yit).second;
        if(!xopen.size()) {
          ok = false;break;
        }
        int i = xopen.front();
        if(ans.at(i).at(j)!=-1) {
          ok = false;break;
        }
        ans.at(i).at(j) = a;
        for(auto ii : xopen) {
          if(ii==i) continue;
          q.push(pair(ii,j));
        }
        yopen.push_back(j);
      } else {// both not found
        if(!q.size()) {
          ok = false;break;
        }
        auto [i,j] = q.front();q.pop();
        if(ans.at(i).at(j)!=-1) {
          ok = false;break;
        }
        ans.at(i).at(j) = a;
      }
    }
    if(ok) {
      cout<<Yes<<endl;
      rep(i,n) {
        rep(j,m) {
          if(j)cout<<" ";
          cout<<ans.at(i).at(j)+1;
        }
        cout << endl;
      }
    } else {
      cout << No << endl;
    }
  }

  return 0;
}
