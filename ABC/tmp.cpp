#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500005

int N;
string S;

struct lazy_segtree {
    vector<int> node, lazy;
    int sz;

    lazy_segtree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        node.resize(2 * sz - 1, 0);
        lazy.resize(2 * sz - 1, 0);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] = (r - l) - node[k];
            if (r - l > 1) {
                lazy[2 * k + 1] ^= 1;
                lazy[2 * k + 2] ^= 1;
            }
            lazy[k] = 0;
        }
    }

    void update(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            node[k] = (r - l) - node[k];
            if (r - l > 1) {
                lazy[2 * k + 1] ^= 1;
                lazy[2 * k + 2] ^= 1;
            }
            return;
        }
        update(a, b, x, 2 * k + 1, l, (l + r) / 2);
        update(a, b, x, 2 * k + 2, (l + r) / 2, r);
        node[k] = node[2 * k + 1] + node[2 * k + 2];
    }

    int query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        eval(k, l, r);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

int main() {
    cin >> S;
    N = S.size();

    lazy_segtree seg(N);

    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == '(' && S[i + 1] == ')') {
            seg.update(i, i + 2, 1);
        }
    }

    string ans = "";
    for (int i = 0; i < N; ++i) {
        if (S[i] == '(' || S[i] == ')') continue;
        if (seg.query(i, i + 1) % 2 == 0) {
            ans += S[i];
        } else {
            ans += (islower(S[i]) ? toupper(S[i]) : tolower(S[i]));
        }
    }

    cout << ans << endl;

    return 0;
}
