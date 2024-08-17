#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAX_VAL = 1000000; // A[i], B[i]の取りうる最大の値

// Zobristハッシュのためのランダムな値を格納
vector<ll> zobrist_table(MAX_VAL + 1);

// 配列の累積Zobristハッシュを計算する関数
vector<ll> compute_zobrist_prefix(const vector<int>& arr) {
    int n = arr.size();
    vector<ll> prefix_hash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_hash[i + 1] = prefix_hash[i] + zobrist_table[arr[i]];
    }
    return prefix_hash;
}

// 区間 [l, r] のZobristハッシュを計算
ll get_zobrist_hash(const vector<ll>& prefix_hash, int l, int r) {
    return prefix_hash[r + 1] - prefix_hash[l];
}

int main() {
    // Zobristハッシュ用のランダム値を生成
    for (int i = 0; i <= MAX_VAL; i++) {
        zobrist_table[i] = rng();
    }

    int n, q;
    cin >> n >> q;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    // A と B の累積Zobristハッシュを計算
    vector<ll> prefix_A = compute_zobrist_prefix(A);
    vector<ll> prefix_B = compute_zobrist_prefix(B);

    while (q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        l--; r--; L--; R--;

        ll hash_A = get_zobrist_hash(prefix_A, l, r);
        ll hash_B = get_zobrist_hash(prefix_B, L, R);

        if (hash_A == hash_B) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
