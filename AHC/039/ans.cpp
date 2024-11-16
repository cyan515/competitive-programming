#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const int P_MAX = 100000;
const int BLOCK_LEN = 100;
const int BLOCK_SIZE = P_MAX / BLOCK_LEN + 10;

struct Point {
  int x,y;
  Point(int x=0,int y=0) : x(x),y(y){}
};

void answer(set<pair<int,int>>& ans) {
  cout << ans.size() << endl;
  auto it = ans.begin();
  while(ans.size()) {
    auto [x,y] = *it;
    ans.erase(it);
    cout << min((x-1)*BLOCK_LEN,100000) << " " << min((y-1)*BLOCK_LEN,100000) << endl;
    if(ans.size()==0) break;
    for(auto nit = ans.begin();;nit++) {
      if((*nit).first==x||(*nit).second==y) {
        it = nit;
        break;
      }
    }
  }
}

int sum(vector<vector<int>>& pref,int up,int down,int right,int left) {
  return pref.at(right).at(up)-pref.at(right).at(down)-pref.at(left).at(up)+pref.at(left).at(down);
}

void solve(int n,vector<Point>& ok,vector<Point>& ng) {
  
  vector blocks(BLOCK_SIZE,vector<int>(BLOCK_SIZE));
  rep(i,n) {
    auto [x,y] = ok.at(i);
    blocks.at(x/BLOCK_LEN+1).at(y/BLOCK_LEN+1)++;
  }
  rep(i,n) {
    auto [x,y] = ng.at(i);
    blocks.at(x/BLOCK_LEN+1).at(y/BLOCK_LEN+1)--;
  }
  reps(i,1,BLOCK_SIZE) reps(j,1,BLOCK_SIZE) {
    blocks.at(i).at(j) += blocks.at(i-1).at(j) + blocks.at(i).at(j-1) - blocks.at(i-1).at(j-1);
  }
  int ma = -1;
  int up = BLOCK_SIZE;
  int down = 1;
  int right = BLOCK_SIZE;
  int left = 1;
  reps(r,1,BLOCK_SIZE) reps(u,1,BLOCK_SIZE) {
    rep(_,10) {
      int d = rand()%u;
      int l = rand()%r;
      if(chmax(ma,blocks.at(r).at(u)-blocks.at(r).at(d)-blocks.at(l).at(u)+blocks.at(l).at(d))) {
        up = u+1;
        down = d+1;
        right = r+1;
        left = l+1;
      }
    }
  }
  
  vector<pair<int,int>> ans;
  ans.push_back(pair(left,down));
  ans.push_back(pair(right,down));
  ans.push_back(pair(right,up));
  ans.push_back(pair(left,up));
  
  int mx,my;
  int temp = sum(blocks,up,down,right,left);
  rep(_,500000) {
    mx = left + rand()%abs(right-left);
    my = down + rand()%abs(up-down);
    if(mx<=left || right<=mx || my<=down || up<=my) continue;
    if(chmax(ma,temp-sum(blocks,my,down-1,mx,left-1))) {
      vector<pair<int,int>> nans;
      nans.push_back(pair(mx,my));
      nans.push_back(pair(mx,down));
      nans.push_back(pair(left,my));
      nans.push_back(pair(right,down));
      nans.push_back(pair(right,up));
      nans.push_back(pair(left,up));
      swap(ans,nans);
    }
    if(chmax(ma,temp-sum(blocks,my,down-1,right,mx-1))) {
      vector<pair<int,int>> nans;
      nans.push_back(pair(mx,my));
      nans.push_back(pair(mx,down));
      nans.push_back(pair(right,my));
      nans.push_back(pair(left,down));
      nans.push_back(pair(right,up));
      nans.push_back(pair(left,up));
      swap(ans,nans);
    }
    if(chmax(ma,temp-sum(blocks,up,my-1,right,mx-1))) {
      // remove right up
      vector<pair<int,int>> nans;
      nans.push_back(pair(mx,my));
      nans.push_back(pair(mx,up));
      nans.push_back(pair(right,my));
      nans.push_back(pair(left,down));
      nans.push_back(pair(right,down));
      nans.push_back(pair(left,up));
      swap(ans,nans);
    }
    if(chmax(ma,temp-sum(blocks,up,my-1,mx,left-1))) {
      // remove left up
      vector<pair<int,int>> nans;
      nans.push_back(pair(mx,my));
      nans.push_back(pair(mx,up));
      nans.push_back(pair(left,my));
      nans.push_back(pair(left,down));
      nans.push_back(pair(right,down));
      nans.push_back(pair(right,up));
      swap(ans,nans);
    }
  }
  
  set<pair<int,int>> st;
  rep(i,ans.size()) {
    st.insert(ans.at(i));
  }
  answer(st);
}

int main() {
  int n;cin>>n;
  vector<Point> ok(n),ng(n);
  rep(i,n) {
    int x,y;cin>>x>>y;
    ok.at(i) = Point(x,y);
  }
  rep(i,n) {
    int x,y;cin>>x>>y;
    ng.at(i) = Point(x,y);
  }
  solve(n,ok,ng);
  
  return 0;
}
