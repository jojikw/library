---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/range_query/fenwick_tree.test.cpp
    title: verify/ds/range_query/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/range_query/fenwick_tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\nnamespace BIT\n{\nconst int N=1000005;\n\
    int n;\nll t[N];\nvoid init(int _n)\n{\n        n=_n;\n        for(int i=0;i<=n;i++)\n\
    \                t[i]=0;\n}\nvoid add(int x, ll v)\n{\n        for(;x<=n;x+=x&-x)\n\
    \                t[x]+=v;\n}\nll qry(int x)\n{\n        ll ret=0;\n        for(;x;x-=x&-x)\n\
    \                ret+=t[x];\n        return ret;\n}\nll qry(int l, int r){return\
    \ qry(r)-qry(l-1);}\nint kth(ll k)\n{\n        int x=0;\n        for(int b=1<<20;b;b>>=1)\n\
    \                if(x+b<=n&&t[x+b]<k)\n                        x+=b,k-=t[x];\n\
    \        return x+1;\n}\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\nnamespace BIT\n{\nconst int N=1000005;\nint n;\nll t[N];\nvoid init(int\
    \ _n)\n{\n        n=_n;\n        for(int i=0;i<=n;i++)\n                t[i]=0;\n\
    }\nvoid add(int x, ll v)\n{\n        for(;x<=n;x+=x&-x)\n                t[x]+=v;\n\
    }\nll qry(int x)\n{\n        ll ret=0;\n        for(;x;x-=x&-x)\n            \
    \    ret+=t[x];\n        return ret;\n}\nll qry(int l, int r){return qry(r)-qry(l-1);}\n\
    int kth(ll k)\n{\n        int x=0;\n        for(int b=1<<20;b;b>>=1)\n       \
    \         if(x+b<=n&&t[x+b]<k)\n                        x+=b,k-=t[x];\n      \
    \  return x+1;\n}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/range_query/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-10-06 13:15:37+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/range_query/fenwick_tree.test.cpp
documentation_of: ds/range_query/fenwick_tree.hpp
layout: document
title: Fenwick tree (binary indexed tree)
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
