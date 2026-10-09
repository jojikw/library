---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/dsu/dsu.hpp
    title: ds/dsu/dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/ds/dsu/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\n#line 3\
    \ \"ds/dsu/dsu.hpp\"\nusing namespace std;\nusing ll=long long;\nnamespace DSU\n\
    {\nconst int N=200005;\nint fa[N],sz[N];\nvoid init(int n)\n{\n        for(int\
    \ i=1;i<=n;i++)\n                fa[i]=i,sz[i]=1;\n}\nint find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}\n\
    bool merge(int x, int y)\n{\n        x=find(x);\n        y=find(y);\n        if(x==y)\n\
    \                return false;\n        if(sz[x]<sz[y])\n                swap(x,y);\n\
    \        fa[y]=x;\n        sz[x]+=sz[y];\n        return true;\n}\nstruct Pot\n\
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
    \                   comps++;\n                }\n        }\n}\n};\n}\n#line 6\
    \ \"verify/ds/dsu/dsu.test.cpp\"\nvoid solve()\n{\n        int n,q;cin>>n>>q;\n\
    \        DSU::init(n);\n        while(q--)\n        {\n                int t,u,v;cin>>t>>u>>v;\n\
    \                u++;\n                v++;\n                if(t==0)\n      \
    \                  DSU::merge(u,v);\n                else\n                  \
    \      cout<<(DSU::find(u)==DSU::find(v))<<'\\n';\n        }\n}\nint main()\n\
    {\n        ios::sync_with_stdio(false);cin.tie(NULL);\n        int tc=1;\n   \
    \     // cin>>tc;\n        while(tc--)solve();\n        return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\n#include \"ds/dsu/dsu.hpp\"\nvoid solve()\n\
    {\n        int n,q;cin>>n>>q;\n        DSU::init(n);\n        while(q--)\n   \
    \     {\n                int t,u,v;cin>>t>>u>>v;\n                u++;\n     \
    \           v++;\n                if(t==0)\n                        DSU::merge(u,v);\n\
    \                else\n                        cout<<(DSU::find(u)==DSU::find(v))<<'\\\
    n';\n        }\n}\nint main()\n{\n        ios::sync_with_stdio(false);cin.tie(NULL);\n\
    \        int tc=1;\n        // cin>>tc;\n        while(tc--)solve();\n       \
    \ return 0;\n}\n"
  dependsOn:
  - ds/dsu/dsu.hpp
  isVerificationFile: true
  path: verify/ds/dsu/dsu.test.cpp
  requiredBy: []
  timestamp: '2026-10-09 12:57:47+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/dsu/dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dsu/dsu.test.cpp
- /verify/verify/ds/dsu/dsu.test.cpp.html
title: verify/ds/dsu/dsu.test.cpp
---
