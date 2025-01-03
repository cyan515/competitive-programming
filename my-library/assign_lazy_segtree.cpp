#include <vector>
#include <cstdio>

using S = int;
S op(S l, S r) { return l * r; }
S id() { return 1; }

/// @brief 区間代入可能な遅延セグメント木
/// @see https://noshi91.hatenablog.com/entry/2019/10/05/203704
/// @see https://noshi91.github.io/Library/gomi/assign_segment_tree.cpp.html
class assign_lazy_segtree {
private:
  class node {
  public:
    S sum;
    S *lazy;
    node() : sum(id()), lazy(nullptr) {}
    S get() {
      if (lazy) {
        return *lazy;
      } else {
        return sum;
      }
    }
  };

  int height;
  std::vector<node> tree;
  std::vector<S> table;

  void push(int index) {
    if (tree[index].lazy) {
      tree[index * 2].lazy = tree[index].lazy - 1;
      tree[index * 2 + 1].lazy = tree[index].lazy - 1;
      tree[index].sum = *tree[index].lazy;
      tree[index].lazy = nullptr;
    }
  }

  S prod(int index, int n_left, int n_right, int q_left, int q_right) {
    if (q_left <= n_left && n_right <= q_right) {
      return tree[index].get();
    }
    if (n_right <= q_left || q_right <= n_left) {
      return id();
    }
    push(index);
    int n_mid = (n_left + n_right) / 2;
    return op(prod(index * 2, n_left, n_mid, q_left, q_right),
              prod(index * 2 + 1, n_mid, n_right, q_left, q_right));
  }

  void apply(int index, int n_left, int n_right, int q_left, int q_right, S *lazy) {
    if (q_left <= n_left && n_right <= q_right) {
      tree[index].lazy = lazy;
      return;
    }
    if (n_right <= q_left || q_right <= n_left) {
      return;
    }
    push(index);
    int n_mid = (n_left + n_right) / 2;
    apply(index * 2, n_left, n_mid, q_left, q_right, lazy - 1);
    apply(index * 2 + 1, n_mid, n_right, q_left, q_right, lazy - 1);
    tree[index].sum = op(tree[index * 2].get(), tree[index * 2 + 1].get());
  }

public:
  assign_lazy_segtree(int n) {
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

  void print() {
    for(int i = 0; i < size(); i++) {
      if(i) fprintf(stderr, " ");
      fprintf(stderr, "%d", prod(i,i+1));
    }
    fprintf(stderr, "\n");
  }

  S prod(int l, int r) { return prod(1, 0, size(), l, r); }

  void apply(int l, int r, S value) {
    for (int i = 0; i < height; ++i) {
      table.push_back(value);
      value = op(value, value);
    }
    apply(1, 0, size(), l, r, &table.back());
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
