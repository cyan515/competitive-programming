#include <bits/stdc++.h>
using namespace std;

template <class Type>
class weighted_union_find {
public:

	weighted_union_find() = default;

	explicit weighted_union_find(size_t n)
		: m_parents(n), m_sizes(n, 1), m_diffWeights(n) {
		iota(m_parents.begin(), m_parents.end(), 0);
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
				swap(a, b);
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

	vector<int> m_parents;
	vector<int> m_sizes;
	vector<Type> m_diffWeights;

	Type weight(int i) {
		leader(i);
		return m_diffWeights[i];
	}
};
