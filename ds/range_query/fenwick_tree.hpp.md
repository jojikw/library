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
    int n;\nll t[N];\nll t1[N],t2[N];\nvoid init(int _n)\n{\n        n=_n;\n     \
    \   for(int i=0;i<=n;i++)\n                t[i]=0,t1[i]=0,t2[i]=0;\n}\nvoid add(int\
    \ x, ll v)\n{\n        for(;x<=n;x+=x&-x)\n                t[x]+=v;\n}\nll qry(int\
    \ x)\n{\n        ll ret=0;\n        for(;x;x-=x&-x)\n                ret+=t[x];\n\
    \        return ret;\n}\nll qry(int l, int r){return qry(r)-qry(l-1);}\nint kth(ll\
    \ k)\n{\n        int x=0;\n        for(int b=1<<20;b;b>>=1)\n                if(x+b<=n&&t[x+b]<k)\n\
    \                        x+=b,k-=t[x];\n        return x+1;\n}\nvoid add_pt(int\
    \ x, ll v)\n{\n        for(int i=x;i<N;i+=i&-i)\n                t1[i]+=v,t2[i]+=v*x;\n\
    }\nvoid add_range(int l, int r, ll v)\n{\n        add_pt(l,v);\n        add_pt(r+1,-v);\n\
    }\nll qry_range(int x)\n{\n        ll s1=0,s2=0;\n        for(int i=x;i;i-=i&-i)\n\
    \                s1+=t1[i],s2+=t2[i];\n        return s1*(x+1)-s2;\n}\nll qry_range(int\
    \ l, int r){return qry_range(r)-qry_range(l-1);}\n}\nnamespace BIT2D\n{\nconst\
    \ int N=2005;\nll t[N][N];\nint n,m;\nvoid init(int _n, int _m)\n{\n        n=_n;\n\
    \        m=_m;\n        for(int i=0;i<=n;i++)\n                for(int j=0;j<=m;j++)\n\
    \                        t[i][j]=0;\n}\nvoid add(int x, int y, ll v)\n{\n    \
    \    for(int i=x;i<=n;i+=i&-i)\n                for(int j=y;j<=m;j+=j&-j)\n  \
    \                      t[i][j]+=v;\n}\nll qry(int x, int y)\n{\n        ll s=0;\n\
    \        for(int i=x;i>0;i-=i&-i)\n                for(int j=y;j>0;j-=j&-j)\n\
    \                        s+=t[i][j];\n        return s;\n}\nll qry_rect(int x1,\
    \ int y1, int x2, int y2){return qry(x2,y2)-qry(x1-1,y2)-qry(x2,y1-1)+qry(x1-1,y1-1);}\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\nnamespace BIT\n{\nconst int N=1000005;\nint n;\nll t[N];\nll t1[N],t2[N];\n\
    void init(int _n)\n{\n        n=_n;\n        for(int i=0;i<=n;i++)\n         \
    \       t[i]=0,t1[i]=0,t2[i]=0;\n}\nvoid add(int x, ll v)\n{\n        for(;x<=n;x+=x&-x)\n\
    \                t[x]+=v;\n}\nll qry(int x)\n{\n        ll ret=0;\n        for(;x;x-=x&-x)\n\
    \                ret+=t[x];\n        return ret;\n}\nll qry(int l, int r){return\
    \ qry(r)-qry(l-1);}\nint kth(ll k)\n{\n        int x=0;\n        for(int b=1<<20;b;b>>=1)\n\
    \                if(x+b<=n&&t[x+b]<k)\n                        x+=b,k-=t[x];\n\
    \        return x+1;\n}\nvoid add_pt(int x, ll v)\n{\n        for(int i=x;i<N;i+=i&-i)\n\
    \                t1[i]+=v,t2[i]+=v*x;\n}\nvoid add_range(int l, int r, ll v)\n\
    {\n        add_pt(l,v);\n        add_pt(r+1,-v);\n}\nll qry_range(int x)\n{\n\
    \        ll s1=0,s2=0;\n        for(int i=x;i;i-=i&-i)\n                s1+=t1[i],s2+=t2[i];\n\
    \        return s1*(x+1)-s2;\n}\nll qry_range(int l, int r){return qry_range(r)-qry_range(l-1);}\n\
    }\nnamespace BIT2D\n{\nconst int N=2005;\nll t[N][N];\nint n,m;\nvoid init(int\
    \ _n, int _m)\n{\n        n=_n;\n        m=_m;\n        for(int i=0;i<=n;i++)\n\
    \                for(int j=0;j<=m;j++)\n                        t[i][j]=0;\n}\n\
    void add(int x, int y, ll v)\n{\n        for(int i=x;i<=n;i+=i&-i)\n         \
    \       for(int j=y;j<=m;j+=j&-j)\n                        t[i][j]+=v;\n}\nll\
    \ qry(int x, int y)\n{\n        ll s=0;\n        for(int i=x;i>0;i-=i&-i)\n  \
    \              for(int j=y;j>0;j-=j&-j)\n                        s+=t[i][j];\n\
    \        return s;\n}\nll qry_rect(int x1, int y1, int x2, int y2){return qry(x2,y2)-qry(x1-1,y2)-qry(x2,y1-1)+qry(x1-1,y1-1);}\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/range_query/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-10-07 17:33:01+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/range_query/fenwick_tree.test.cpp
documentation_of: ds/range_query/fenwick_tree.hpp
layout: document
title: Fenwick tree (binary indexed tree)
---

# Fenwick tree (binary indexed tree)

Point update and prefix sum query on an array, plus range-add and 2D variants.

## When to use

Use this for point updates with prefix and range sums, k-th prefix search, and the 2D grid variant. Prefer the lazy segment tree when you need range adds with lazy propagation over arbitrary intervals.

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
