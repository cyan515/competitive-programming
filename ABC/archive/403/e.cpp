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

/// @see https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
template< unsigned mod >
struct rolling_hash {
  vector< unsigned > hashed, power;
 
  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  rolling_hash(){
  }
 
  rolling_hash(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }
 
  rolling_hash(const vector<int> &a, unsigned base = 10007) {
    int sz = (int) a.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + a[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  // 半開区間
  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }
 
  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }
 
  int LCP(const rolling_hash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

struct multi_rolling_hash {

  multi_rolling_hash(const string &s, unsigned base1 = 10007, unsigned base2 = 9973) {
    rh1 = rolling_hash<1000000007>(s, base1);
    rh2 = rolling_hash<1000000009>(s, base2);
  }

  multi_rolling_hash(const vector<int> &a, unsigned base1 = 10007, unsigned base2 = 9973) {
    rh1 = rolling_hash<1000000007>(a, base1);
    rh2 = rolling_hash<1000000009>(a, base2);
  }

  // 半開区間
  pair<unsigned,unsigned> get(int l, int r) const {
    return pair(rh1.get(l, r), rh2.get(l, r));
  }

private:
  rolling_hash<1000000007> rh1;
  rolling_hash<1000000009> rh2;
};

// https://algo-logic.info/trie-tree/
/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
    insert(word): 単語 word を Trie 木に挿入する
    search(word): 単語 word が Trie 木にあるか判定する
    start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
    count(): 挿入した単語の数を返す
    size(): Trie 木の頂点数を返す
    計算量：insert, search ともに O(M)（Mは単語の長さ）
*/
template <int char_size, int base>
struct Trie {
    struct Node {            // 頂点を表す構造体
        vector<int> next;    // 子の頂点番号を格納。存在しなければ-1
        vector<int> accept;  // 末端がこの頂点になる単語の word_id を保存
        int c;               // base からの間隔をint型で表現したもの
        int common;          // いくつの単語がこの頂点を共有しているか
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };
    vector<Node> nodes;  // trie 木本体
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }
    // 単語の挿入
    void insert(const string &word, int word_id) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = (int)nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);
    }
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }
    // 単語とprefixの検索
    bool search(const string &word, bool prefix = false) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].accept.size() > 0;
    }
    // prefix を持つ単語が存在するかの検索
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }
    // 挿入した単語の数
    int count() const {
        return (nodes[0].common);
    }
    // Trie木のノード数
    int size() const {
        return ((int)nodes.size());
    }

    void remove(const string &s) {
      int cur = 0;
      vector<int> path = {0};
  
      for (char ch : s) {
        int c = (int)(ch - base);
        int next_id = nodes[cur].next[c];
        if (next_id == -1) {
          return;
        }
        cur = next_id;
        path.push_back(cur);
      }
  
      int cnt = nodes[cur].common;
      if (cnt == 0) return;
  
      auto dfs = [&](auto self, int u) -> void {
        nodes[u].common = 0;
        nodes[u].accept.clear();
        for (int i = 0; i < char_size; i++) {
          int v = nodes[u].next[i];
          if (v != -1) {
            self(self, v);
            nodes[u].next[i] = -1;
          }
        }
      };
      dfs(dfs, cur);
  
      for (int id : path) {
        nodes[id].common -= cnt;
      }
    }
};

int main() {
  int Q;cin>>Q;
  ll ans = 0;
  map<pair<int,int>,ll> x,y;
  Trie<26,'a'> trie;
  while(Q--) {
    int t;cin>>t;
    string s;cin>>s;
    multi_rolling_hash h(s);
    if(t==1) {
      bool ok = true;
      reps(i,1,s.size()+1) {
        if(x.count(h.get(0,i))) ok = false;
      }
      if(ok) {
        x[h.get(0,s.size())]++;
        trie.remove(s);
        ans -= trie.start_with(s);
      }
    } else {
      // y[h.get(0,s.size())]++;
      bool ok = true;
      reps(i,1,s.size()+1) {
        auto it = x.find(h.get(0,i));
        if(it==x.end()) continue;
        ok = false;
        break;
      }
      if(ok) ans++, trie.insert(s);
    }
    // cout << ans << endl;
    cout << trie.count() << endl;
  }

  return 0;
}
