---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/range_query/fenwick_tree.hpp
    title: ds/range_query/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/ds/range_query/fenwick_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\n#line 3 \"ds/range_query/fenwick_tree.hpp\"\
    \nusing namespace std;\nusing ll=long long;\nnamespace BIT\n{\nconst int N=1000005;\n\
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
    }\n#line 6 \"verify/ds/range_query/fenwick_tree.test.cpp\"\nint n,q;\nvoid solve()\n\
    {\n        cin>>n>>q;\n        BIT::init(n);\n        for(int i=1;i<=n;i++)\n\
    \        {\n                ll x;cin>>x;\n                BIT::add(i,x);\n   \
    \     }\n        while(q--)\n        {\n                int t,a,b;cin>>t>>a>>b;\n\
    \                if(t==0)\n                        BIT::add(a+1,b);\n        \
    \        else\n                        cout<<BIT::qry(a+1,b)<<'\\n';\n       \
    \ }\n}\nint main()\n{\n        ios::sync_with_stdio(false);cin.tie(NULL);\n  \
    \      int tc=1;\n        // cin>>tc;\n        while(tc--)solve();\n        return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\n#include\
    \ \"ds/range_query/fenwick_tree.hpp\"\nint n,q;\nvoid solve()\n{\n        cin>>n>>q;\n\
    \        BIT::init(n);\n        for(int i=1;i<=n;i++)\n        {\n           \
    \     ll x;cin>>x;\n                BIT::add(i,x);\n        }\n        while(q--)\n\
    \        {\n                int t,a,b;cin>>t>>a>>b;\n                if(t==0)\n\
    \                        BIT::add(a+1,b);\n                else\n            \
    \            cout<<BIT::qry(a+1,b)<<'\\n';\n        }\n}\nint main()\n{\n    \
    \    ios::sync_with_stdio(false);cin.tie(NULL);\n        int tc=1;\n        //\
    \ cin>>tc;\n        while(tc--)solve();\n        return 0;\n}\n"
  dependsOn:
  - ds/range_query/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/ds/range_query/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-07 17:33:01+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/range_query/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/range_query/fenwick_tree.test.cpp
- /verify/verify/ds/range_query/fenwick_tree.test.cpp.html
title: verify/ds/range_query/fenwick_tree.test.cpp
---
