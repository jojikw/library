---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/dsu/dsu.test.cpp
    title: verify/ds/dsu/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/dsu/dsu.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll=long long;\nnamespace DSU\n{\nconst int N=200005;\nint fa[N],sz[N];\n\
    void init(int n)\n{\n        for(int i=1;i<=n;i++)\n                fa[i]=i,sz[i]=1;\n\
    }\nint find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}\nbool merge(int x, int\
    \ y)\n{\n        x=find(x);\n        y=find(y);\n        if(x==y)\n          \
    \      return false;\n        if(sz[x]<sz[y])\n                swap(x,y);\n  \
    \      fa[y]=x;\n        sz[x]+=sz[y];\n        return true;\n}\nstruct Pot\n\
    {\nint p[N],sz[N];\nll val[N];\nint mod=998244353;\nll norm(ll x){return (x%mod+mod)%mod;}\n\
    void init(int n, int _mod=998244353)\n{\n        mod=_mod;\n        for(int i=1;i<=n;i++)\n\
    \        {\n                p[i]=i;\n                sz[i]=1;\n              \
    \  val[i]=0;\n        }\n}\nint find(int u)\n{\n        if(p[u]==u)\n        \
    \        return u;\n        int r=find(p[u]);\n        val[u]=(val[u]+val[p[u]])%mod;\n\
    \        return p[u]=r;\n}\nbool unite(int u, int v, ll w)\n{\n        w=norm(w);\n\
    \        int ru=find(u),rv=find(v);\n        if(ru==rv)\n                return\
    \ norm(val[u]-val[v])==w;\n        if(sz[ru]<sz[rv])\n        {\n            \
    \    p[ru]=rv;\n                val[ru]=norm(val[v]-val[u]+w);\n             \
    \   sz[rv]+=sz[ru];\n        }\n        else\n        {\n                p[rv]=ru;\n\
    \                val[rv]=norm(val[u]-val[v]-w);\n                sz[ru]+=sz[rv];\n\
    \        }\n        return true;\n}\npair<bool,ll> diff(int u, int v)\n{\n   \
    \     if(find(u)!=find(v))\n                return {false,0};\n        return\
    \ {true,norm(val[u]-val[v])};\n}\n};\nstruct Rollback\n{\nint n,comps;\nvector<int>\
    \ p,sz;\nstruct Op\n{\nint u,v;\nbool merged;\n};\nvector<Op> his;\nRollback(int\
    \ n=0):n(n),comps(n),p(n+1),sz(n+1,1){iota(p.begin(),p.end(),0);}\nint find(int\
    \ x)\n{\n        while(x!=p[x])\n                x=p[x];\n        return x;\n\
    }\nbool unite(int a, int b)\n{\n        a=find(a);\n        b=find(b);\n     \
    \   if(a==b)\n        {\n                his.push_back({a,b,false});\n       \
    \         return false;\n        }\n        if(sz[a]<sz[b])\n                swap(a,b);\n\
    \        p[b]=a;\n        sz[a]+=sz[b];\n        comps--;\n        his.push_back({a,b,true});\n\
    \        return true;\n}\nint snapshot(){return his.size();}\nvoid rollback(int\
    \ t)\n{\n        while((int)his.size()>t)\n        {\n                auto [a,b,m]=his.back();\n\
    \                his.pop_back();\n                if(m)\n                {\n \
    \                       sz[a]-=sz[b];\n                        p[b]=b;\n     \
    \                   comps++;\n                }\n        }\n}\n};\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\nnamespace DSU\n{\nconst int N=200005;\nint fa[N],sz[N];\nvoid init(int\
    \ n)\n{\n        for(int i=1;i<=n;i++)\n                fa[i]=i,sz[i]=1;\n}\n\
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}\nbool merge(int x, int y)\n\
    {\n        x=find(x);\n        y=find(y);\n        if(x==y)\n                return\
    \ false;\n        if(sz[x]<sz[y])\n                swap(x,y);\n        fa[y]=x;\n\
    \        sz[x]+=sz[y];\n        return true;\n}\nstruct Pot\n{\nint p[N],sz[N];\n\
    ll val[N];\nint mod=998244353;\nll norm(ll x){return (x%mod+mod)%mod;}\nvoid init(int\
    \ n, int _mod=998244353)\n{\n        mod=_mod;\n        for(int i=1;i<=n;i++)\n\
    \        {\n                p[i]=i;\n                sz[i]=1;\n              \
    \  val[i]=0;\n        }\n}\nint find(int u)\n{\n        if(p[u]==u)\n        \
    \        return u;\n        int r=find(p[u]);\n        val[u]=(val[u]+val[p[u]])%mod;\n\
    \        return p[u]=r;\n}\nbool unite(int u, int v, ll w)\n{\n        w=norm(w);\n\
    \        int ru=find(u),rv=find(v);\n        if(ru==rv)\n                return\
    \ norm(val[u]-val[v])==w;\n        if(sz[ru]<sz[rv])\n        {\n            \
    \    p[ru]=rv;\n                val[ru]=norm(val[v]-val[u]+w);\n             \
    \   sz[rv]+=sz[ru];\n        }\n        else\n        {\n                p[rv]=ru;\n\
    \                val[rv]=norm(val[u]-val[v]-w);\n                sz[ru]+=sz[rv];\n\
    \        }\n        return true;\n}\npair<bool,ll> diff(int u, int v)\n{\n   \
    \     if(find(u)!=find(v))\n                return {false,0};\n        return\
    \ {true,norm(val[u]-val[v])};\n}\n};\nstruct Rollback\n{\nint n,comps;\nvector<int>\
    \ p,sz;\nstruct Op\n{\nint u,v;\nbool merged;\n};\nvector<Op> his;\nRollback(int\
    \ n=0):n(n),comps(n),p(n+1),sz(n+1,1){iota(p.begin(),p.end(),0);}\nint find(int\
    \ x)\n{\n        while(x!=p[x])\n                x=p[x];\n        return x;\n\
    }\nbool unite(int a, int b)\n{\n        a=find(a);\n        b=find(b);\n     \
    \   if(a==b)\n        {\n                his.push_back({a,b,false});\n       \
    \         return false;\n        }\n        if(sz[a]<sz[b])\n                swap(a,b);\n\
    \        p[b]=a;\n        sz[a]+=sz[b];\n        comps--;\n        his.push_back({a,b,true});\n\
    \        return true;\n}\nint snapshot(){return his.size();}\nvoid rollback(int\
    \ t)\n{\n        while((int)his.size()>t)\n        {\n                auto [a,b,m]=his.back();\n\
    \                his.pop_back();\n                if(m)\n                {\n \
    \                       sz[a]-=sz[b];\n                        p[b]=b;\n     \
    \                   comps++;\n                }\n        }\n}\n};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dsu/dsu.hpp
  requiredBy: []
  timestamp: '2026-10-09 12:57:47+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dsu/dsu.test.cpp
documentation_of: ds/dsu/dsu.hpp
layout: document
title: Disjoint set union
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
