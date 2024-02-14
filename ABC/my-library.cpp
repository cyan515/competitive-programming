#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
const ll LINF = 3001001001001001001;
using ll = long long;

// BFS
void bfs() {
  int n;
  vector g(n,vector<int>(0));

  queue<int> q;
  q.push(0);
  vector<int> d(n,-1);
  d.at(0) = 0;
  while(q.size()) {
    int v = q.front();q.pop();
    for(int ele : g.at(v)) {
      if(d.at(ele)!=-1) continue;
      d.at(ele) = d.at(v)+1;
      q.push(ele);
    }
  }
}

// ダイクストラ法 dijkstra method
// G の pair は <辺の重み, 頂点番号> です。
vector<ll> dijkstra(const vector<vector<pair<ll,ll>>>& G,int V=0) {
  
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  q.emplace(0,V);
  vector<ll> dists(G.size(),LINF);
  dists.at(V) = 0;
  while(q.size()) {
    auto [d,v] = q.top();q.pop();
    if(dists.at(v) < d) continue;
    for(auto [w,nv] : G.at(v)) {
      if(dists.at(nv) <= dists.at(v)+w) continue;
      dists.at(nv) = dists.at(v) + w;
      q.emplace(dists.at(v)+w,nv);
    }
  }
  return dists;
}

// DFS
vector<bool> seen;
void dfs(const vector<vector<int>>& G, int V) {
  seen.at(V) = true;

  for (int next : G.at(V)) {
    if (seen.at(next)) continue;
    dfs(G, next);
  }
}

// sqrt の誤差補正込みのやつ　平方数じゃない場合小数点以下切り捨て
ll sqr(ll X) {
  ll R = sqrt(X)-2;
  while((R+1)*(R+1)<=X)R++;
  return R;
}

// 二分探索
int binarySearch(vector<ll> Sorted, ll K) {
  int ok = -1;
  int ng = Sorted.size();
  while(abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    bool flg = true;
    // TODO: flg の判定をする

    if(flg) ok=mid;
    else ng=mid;
  }
  return ok;
}

// 繰り返し二乗法
ll powll(ll BASE, ll EXPONENT) {
  ll RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}

// a * b がオーバーフローするならtrueを返す
// keywords: オーバーフロー オーバフロー
template <class T> bool overflow_if_mul(T a, T b) {
  return (std::numeric_limits<T>::max() / a) < b;
}

// N までの数が素数かどうかの長さ N+1 の vector を返す
// 0, 1 は false
// keywords: 素数判定 エラトステネスの篩 エラトステネスのふるい
vector<bool> eratosthenes(int _N) {

  vector<bool> isprime(_N+1, true);

  isprime[0] = isprime[1] = false;

  for (int p = 2; p <= _N; ++p) {
    if (!isprime[p]) continue;

    for (int q = p * 2; q <= _N; q += p) {
      isprime[q] = false;
    }
  }

  return isprime;
}

// 2進数表現の string を受け取って10進数に変換して返す
// 1 以外は 0 とみなされる
long long binaryToDecimal(string S) {
  int len = S.length();
  long long ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2L;
    if(S.at(i)=='1') ret++;
  }
  return ret;
}

// 10進数表現の int を受け取って BASE 進数に変換して返す
string convert_base(int _N, int BASE) {
  string RET = "";
  if (_N == 0LL) {
    RET = "0";
  } else {
    while (_N > 0) {
      char c = '0' + (_N % BASE);
      RET += c;
      _N /= BASE;
    }
    reverse(RET.begin(), RET.end());
  }
  return RET;
}

std::vector<std::vector<long long>> comb(int n) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

// S の i 文字目以降で最初に文字 c が登場する index
// @see https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

// 拡張ユークリッドの互除法
// 不定方程式の解
long long ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = ext_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

// UnionFind, able to rewind to the previous state by undo()
// Written for Educational Codeforces 62 F, although not verified yet.
// @see https://atcoder.jp/contests/abc328/submissions/47458831
struct rollbackable_dsu {
  using pint = std::pair<int, int>;
  std::vector<int> par, cou;
  std::stack<std::pair<int, pint>> history;
  rollbackable_dsu(int N) : par(N), cou(N, 1) { std::iota(par.begin(), par.end(), 0); }
  int leader(int x) const { return (par[x] == x) ? x : leader(par[x]); }
  bool merge(int x, int y) {
    x = leader(x), y = leader(y);
    if (cou[x] < cou[y]) std::swap(x, y);
    history.emplace(y, pint(par[y], cou[x]));
    return x != y ? par[y] = x, cou[x] += cou[y], true : false;
  }
  void undo() {
    cou[par[history.top().first]] = history.top().second.second;
    par[history.top().first] = history.top().second.first;
    history.pop();
  }
  void reset() {
    while (!history.empty()) undo();
  }
  int size(int x) const { return cou[leader(x)]; }
  bool same(int x, int y) const { return leader(x) == leader(y); }
};

// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/weighted-union-find
template <class Type>
class WeightedUnionFind
{
public:

	WeightedUnionFind() = default;

	/// @brief 重み付き Union-Find 木を構築します。
	/// @param n 要素数
	explicit WeightedUnionFind(size_t n)
		: m_parentsOrSize(n, -1)
		, m_diffWeights(n) {}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parentsOrSize[i] < 0)
		{
			return i;
		}

		const int root = find(m_parentsOrSize[i]);

		m_diffWeights[i] += m_diffWeights[m_parentsOrSize[i]];

		// 経路圧縮
		return (m_parentsOrSize[i] = root);
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @param w (b の重み) - (a の重み)
	void merge(int a, int b, Type w)
	{
		w += weight(a);
		w -= weight(b);

		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (-m_parentsOrSize[a] < -m_parentsOrSize[b])
			{
				std::swap(a, b);
				w = -w;
			}

			m_parentsOrSize[a] += m_parentsOrSize[b];
			m_parentsOrSize[b] = a;
			m_diffWeights[b] = w;
		}
	}

	/// @brief (b の重み) - (a の重み) を返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @remark a と b が同じグループに属さない場合の結果は不定です。
	/// @return (b の重み) - (a の重み)
	Type diff(int a, int b)
	{
		return (weight(b) - weight(a));
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool connected(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return -m_parentsOrSize[find(i)];
	}

private:

	// m_parentsOrSize[i] は i の 親,
	// ただし root の場合は (-1 * そのグループに属する要素数)
	std::vector<int> m_parentsOrSize;

	// 重み
	std::vector<Type> m_diffWeights;

	Type weight(int i)
	{
		find(i); // 経路圧縮
		return m_diffWeights[i];
	}
};

template <class Type>
class weighted_dsu {
public:

	weighted_dsu() = default;

	explicit weighted_dsu(size_t n)
		: m_parents(n), m_sizes(n, 1), m_diffWeights(n) {
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	int leader(int i) {
		if (m_parents[i] == i) {
			return i;
		}

		const int root = leader(m_parents[i]);

		m_diffWeights[i] += m_diffWeights[m_parents[i]];

		return (m_parents[i] = root);
	}

	void merge(int a, int b, Type w) {
		w += weight(a);
		w -= weight(b);

		a = leader(a);
		b = leader(b);

		if (a != b) {
			if (m_sizes[a] < m_sizes[b]) {
				std::swap(a, b);
				w = -w;
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
			m_diffWeights[b] = w;
		}
	}

	Type diff(int a, int b) {
		return (weight(b) - weight(a));
	}

	bool same(int a, int b) {
		return (leader(a) == leader(b));
	}

	int size(int i) {
		return m_sizes[leader(i)];
	}

private:

	std::vector<int> m_parents;
	std::vector<int> m_sizes;
	std::vector<Type> m_diffWeights;

	Type weight(int i) {
		leader(i);
		return m_diffWeights[i];
	}
};

vector<pair<char, int>> run_length(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

class Timer {
    public:
    void start() {
        origin = rdtsc();
    }
    
    inline double get_time() {
        return (rdtsc() - origin) * SECONDS_PER_CLOCK;
    }
    
    private:
    constexpr static double SECONDS_PER_CLOCK = 1 / 3.0e9;
    unsigned long long origin;
    
    inline static unsigned long long rdtsc() {
        unsigned long long lo, hi;
        __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
        return (hi << 32) | lo;
    }
};
