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
using T = int;
T op(T l, T r) { return max(l,r); }
T id() { return -INF; }

class assign_segment_tree {
private:
  class node {
  public:
    T sum;
    T *lazy;
    node() : sum(id()), lazy(nullptr) {}
    T get() {
      if (lazy) {
        return *lazy;
      } else {
        return sum;
      }
    }
  };

  int height;
  std::vector<node> tree;
  std::vector<T> table;

  void push(int index) {
    if (tree[index].lazy) {
      tree[index * 2].lazy = tree[index].lazy - 1;
      tree[index * 2 + 1].lazy = tree[index].lazy - 1;
      tree[index].sum = *tree[index].lazy;
      tree[index].lazy = nullptr;
    }
  }

  T fold(int index, int n_left, int n_right, int q_left, int q_right) {
    if (q_left <= n_left && n_right <= q_right) {
      return tree[index].get();
    }
    if (n_right <= q_left || q_right <= n_left) {
      return id();
    }
    push(index);
    int n_mid = (n_left + n_right) / 2;
    return op(fold(index * 2, n_left, n_mid, q_left, q_right),
              fold(index * 2 + 1, n_mid, n_right, q_left, q_right));
  }

  void assign(int index, int n_left, int n_right, int q_left, int q_right,
              T *lazy) {
    if (q_left <= n_left && n_right <= q_right) {
      tree[index].lazy = lazy;
      return;
    }
    if (n_right <= q_left || q_right <= n_left) {
      return;
    }
    push(index);
    int n_mid = (n_left + n_right) / 2;
    assign(index * 2, n_left, n_mid, q_left, q_right, lazy - 1);
    assign(index * 2 + 1, n_mid, n_right, q_left, q_right, lazy - 1);
    tree[index].sum = op(tree[index * 2].get(), tree[index * 2 + 1].get());
  }

public:
  assign_segment_tree(int n) {
    height = 1;
    int s = 1;
    while (s < n) {
      s *= 2;
      ++height;
    }
    tree.assign(s * 2, node());
    table.reserve(s * 2);
  }

  int size() { return tree.size() / 2; }

  T fold(int first, int last) { return fold(1, 0, size(), first, last); }

  void assign(int first, int last, T value) {
    for (int i = 0; i < height; ++i) {
      table.push_back(value);
      value = op(value, value);
    }
    assign(1, 0, size(), first, last, &table.back());
    if (table.capacity() - table.size() < height) {
      for (int i = 1; i < size(); ++i) {
        push(i);
      }
      for (int i = size(); i != tree.size(); ++i) {
        if (tree[i].lazy) {
          tree[i].sum = *tree[i].lazy;
          tree[i].lazy = nullptr;
        }
      }
      table.clear();
    }
  }
};

int main() {
  int h,w;cin>>h>>w;
  int n;cin>>n;
  vector<tuple<int,int,int,int>> vec(n);
  rep(i,n) {
    int r,c,l;cin>>r>>c>>l;r--;c--;
    vec.at(i) = tuple(r,c,l,i);
  }
  sort(all(vec));
  reverse(all(vec));
  assign_segment_tree seg(w);
  vector<int> ans(n,0);
  seg.assign(0,w,0);
  rep(i,n) {
    auto [r,c,l,idx] = vec.at(i);
    int ma = seg.fold(c,c+l);
    ans.at(idx) = ma+1;
    seg.assign(c,c+l,ma+1);
  }
  rep(i,n) {
    ans.at(i) = h-ans.at(i)+1;
  }
  rep(i,n) cout << ans.at(i) << endl;

  return 0;
}
