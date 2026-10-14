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
  int n,Q;cin>>n>>Q;
  vector<int>a(n,0);
  queue<int>q;
  int ans=0;
  while(Q--){
    int op;cin>>op;
    if(op==1){
      int x;cin>>x;x--;
      ans^=a.at(x);
      a.at(x)++;
      if(a.at(x)==1)q.push(x);
      ans^=a.at(x);
    }else{
      queue<int>q2;
      while(q.size()){
        int x=q.front();q.pop();
        ans^=a.at(x);
        a.at(x)--;
        ans^=a.at(x);
        if(a.at(x)>0)q2.push(x);
      }
      swap(q,q2);
    }
    cout<<ans<<endl;
  }

  return 0;
}
