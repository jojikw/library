---
title: [
  Fenwick tree (binary indexed tree)
]
documentation_of: [
  //ds/range_query/fenwick_tree.hpp
]
---

# Fenwick tree (binary indexed tree)

Point update and prefix sum query on an array.

## Time complexity

| | Time complexity |
|:--|:--|
| Fenwick tree | $\langle O(N), O(\log N) \rangle$ |

## Specification

### Fenwick tree (`namespace BIT`)

| Name | Effect / Return value |
|:--|:--|
| `const int N` | maximum size (`1000005`) |
| `void init(int n);` | $A_1, \dots, A_n \gets 0$ |
| `void add(int x, ll v);` | $A_x \gets A_x + v$ |
| `ll qry(int x);` | $\sum_{i=1}^{x} A_i$ |
| `ll qry(int l, int r);` | $\sum_{i=l}^{r} A_i$ |
| `int kth(ll k);` | minimum $x$ such that $\sum_{i \le x} A_i \ge k$ (requires $A_i \ge 0$) |

## TODO

- Add 2D Fenwick tree (`ds/range_query/fenwick_tree_2d.hpp`).
