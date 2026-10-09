---
title: [
  2D prefix sums
]
documentation_of: [
  //utilities/prefix_2d.hpp
]
---

# 2D prefix sums

Subgrid sums and subgrid additions on a grid.

## When to use

Use this for static grids with many subrectangle sum queries or offline rectangle additions. Prefer the 1D prefix sums for single-row problems and an update-capable structure when cells change between queries.

## Time complexity

| | Time complexity |
|:--|:--|
| `build`, `rebuild` | $O(NM)$ |
| `qry`, `add` | $O(1)$ |

## Specification

### 2D prefix sums (`namespace PREF2D`)

| Name | Effect / Return value |
|:--|:--|
| `const int N` | maximum size (`1005`) |
| `void build(int n, int m, int a[N][N]);` | prefix sums of $1$-indexed $a$ |
| `ll qry(int x1, int y1, int x2, int y2);` | sum of $[x_1..x_2] \times [y_1..y_2]$ |
| `void add(int x1, int y1, int x2, int y2, ll v);` | add $v$ to subgrid |
| `void rebuild(int n, int m);` | materialize pending additions |

## TODO

- No pending items.
