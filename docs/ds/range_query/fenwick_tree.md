---
title: [
  Fenwick tree (binary indexed tree),
  2D Fenwick tree
]
documentation_of: [
  //ds/range_query/fenwick_tree.hpp
]
---

# Fenwick tree (binary indexed tree)

Point update and prefix sum query on an array, plus range-add and 2D variants.

## Time complexity

| | Time complexity |
|:--|:--|
| Fenwick tree | $\langle O(N), O(\log N) \rangle$ |
| 2D Fenwick tree | $\langle O(NM), O(\log N \log M) \rangle$ |

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
| `void add_range(int l, int r, ll v);` | add $v$ to $A_l, \dots, A_r$ |
| `ll qry_range(int x);` | prefix sum with range adds |
| `ll qry_range(int l, int r);` | range sum with range adds |

### 2D Fenwick tree (`namespace BIT2D`)

| Name | Effect / Return value |
|:--|:--|
| `const int N` | maximum rows/columns (`2005`) |
| `void init(int n, int m);` | clear $n \times m$ grid |
| `void add(int x, int y, ll v);` | add $v$ at $(x, y)$ |
| `ll qry(int x, int y);` | sum of $[1..x] \times [1..y]$ |
| `ll qry_rect(int x1, int y1, int x2, int y2);` | sum of $[x_1..x_2] \times [y_1..y_2]$ |

## TODO

- Add verification problem for range-add range-sum and 2D.
