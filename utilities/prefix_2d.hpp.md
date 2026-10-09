---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utilities/prefix_2d.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll=long long;\nnamespace PREF2D\n{\nconst int N=1005;\n\
    ll t[N][N];\nll d[N][N];\nvoid build(int n, int m, int a[N][N])\n{\n        for(int\
    \ i=1;i<=n;i++)\n                for(int j=1;j<=m;j++)\n                     \
    \   t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+a[i][j];\n}\nll qry(int x1, int y1,\
    \ int x2, int y2){return t[x2][y2]-t[x1-1][y2]-t[x2][y1-1]+t[x1-1][y1-1];}\nvoid\
    \ add(int x1, int y1, int x2, int y2, ll v)\n{\n        d[x1][y1]+=v;\n      \
    \  d[x1][y2+1]-=v;\n        d[x2+1][y1]-=v;\n        d[x2+1][y2+1]+=v;\n}\nvoid\
    \ rebuild(int n, int m)\n{\n        for(int i=1;i<=n;i++)\n                for(int\
    \ j=1;j<=m;j++)\n                        d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];\n\
    }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\nnamespace PREF2D\n{\nconst int N=1005;\nll t[N][N];\nll d[N][N];\nvoid\
    \ build(int n, int m, int a[N][N])\n{\n        for(int i=1;i<=n;i++)\n       \
    \         for(int j=1;j<=m;j++)\n                        t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+a[i][j];\n\
    }\nll qry(int x1, int y1, int x2, int y2){return t[x2][y2]-t[x1-1][y2]-t[x2][y1-1]+t[x1-1][y1-1];}\n\
    void add(int x1, int y1, int x2, int y2, ll v)\n{\n        d[x1][y1]+=v;\n   \
    \     d[x1][y2+1]-=v;\n        d[x2+1][y1]-=v;\n        d[x2+1][y2+1]+=v;\n}\n\
    void rebuild(int n, int m)\n{\n        for(int i=1;i<=n;i++)\n               \
    \ for(int j=1;j<=m;j++)\n                        d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];\n\
    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utilities/prefix_2d.hpp
  requiredBy: []
  timestamp: '2026-10-06 17:43:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utilities/prefix_2d.hpp
layout: document
title: 2D prefix sums
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
