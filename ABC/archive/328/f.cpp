#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <class Type>
class weighted_union_find {
public:

	weighted_union_find() = default;

	explicit weighted_union_find(size_t n)
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

int main() {
  ll n,q;cin>>n>>q;
  weighted_union_find<ll> uf(n);
  rep(i,q) {
    ll a,b,d;cin>>a>>b>>d;
    if(!uf.same(a,b)) {
      uf.merge(a,b,d);
      cout << i+1 << " ";
    } else {
      if(uf.diff(a,b)==d) cout << i+1 << " ";
    }
  }
  cout << endl;

  exit(0);
}
