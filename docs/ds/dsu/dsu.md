---
title: Disjoint set union
documentation_of: //ds/dsu/dsu.hpp
---

# Disjoint set union

Union-find with union by size, potentials, and rollback.

## When to use

Use this for incremental connectivity under unions, with weighted potential constraints or rollback snapshots when needed. Prefer offline dynamic connectivity for edge deletions over time, and prefer the link-cut tree for forest link and cut with path queries.

## Time complexity

| | Time complexity |
|:--|:--|
| `find`, `merge` (amortized) | $O(\alpha(N))$ |
| `Pot::find`, `Pot::unite` (amortized) | $O(\alpha(N))$ |
| `Rollback::unite` (no path compression) | $O(\log N)$ |

## Specification

### DSU (`namespace DSU`)

| Name | Effect / Return value |
|:--|:--|
| `const int N` | maximum size (`200005`) |
| `void init(int n);` | $fa_i \gets i$ for $1 \le i \le n$ |
| `int find(int x);` | leader of $x$ with path compression |
| `bool merge(int x, int y);` | union by size; `false` if already same set |

### Potential DSU (`namespace DSU`, `struct Pot`)

Weights are kept modulo `MOD` (set via `init`).

| Name | Effect / Return value |
|:--|:--|
| `void init(int n, int mod);` | reset; all weights modulo $mod$ (default `998244353`) |
| `int find(int u);` | leader of $u$, updating $v$ along the path |
| `bool unite(int u, int v, ll w);` | assert $pot[u] - pot[v] \equiv w \pmod{MOD}$; `false` on contradiction |
| `pair<bool,ll> diff(int u, int v);` | $\{true, (pot[u] - pot[v]) \bmod MOD\}$ if connected, else $\{false, 0\}$ |

### Rollback DSU (`namespace DSU`, `struct Rollback`)

| Name | Effect / Return value |
|:--|:--|
| `Rollback(int n = 0);` | DSU on $1..n$ without path compression |
| `int find(int x);` | leader of $x$ |
| `bool unite(int a, int b);` | union by size, logged; `false` if already same set |
| `int snapshot();` | current history size |
| `void rollback(int t);` | undo everything back to snapshot $t$ |
| `int comps;` | number of connected components |

## TODO

- Add verification problem for `Rollback`.
