---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/range_query/fenwick_tree.hpp
    title: Fenwick tree (binary indexed tree)
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
    int n;\nll t[N];\nvoid init(int _n)\n{\n        n=_n;\n        for(int i=0;i<=n;i++)\n\
    \                t[i]=0;\n}\nvoid add(int x, ll v)\n{\n        for(;x<=n;x+=x&-x)\n\
    \                t[x]+=v;\n}\nll qry(int x)\n{\n        ll ret=0;\n        for(;x;x-=x&-x)\n\
    \                ret+=t[x];\n        return ret;\n}\nll qry(int l, int r){return\
    \ qry(r)-qry(l-1);}\nint kth(ll k)\n{\n        int x=0;\n        for(int b=1<<20;b;b>>=1)\n\
    \                if(x+b<=n&&t[x+b]<k)\n                        x+=b,k-=t[x];\n\
    \        return x+1;\n}\n}\n#line 6 \"verify/ds/range_query/fenwick_tree.test.cpp\"\
    \nint n,q;\nvoid solve()\n{\n        cin>>n>>q;\n        BIT::init(n);\n     \
    \   for(int i=1;i<=n;i++)\n        {\n                ll x;cin>>x;\n         \
    \       BIT::add(i,x);\n        }\n        while(q--)\n        {\n           \
    \     int t,a,b;cin>>t>>a>>b;\n                if(t==0)\n                    \
    \    BIT::add(a+1,b);\n                else\n                        cout<<BIT::qry(a+1,b)<<'\\\
    n';\n        }\n}\nint main()\n{\n        ios::sync_with_stdio(false);cin.tie(NULL);\n\
    \        int tc=1;\n        // cin>>tc;\n        while(tc--)solve();\n       \
    \ return 0;\n}\n"
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
  timestamp: '2026-10-06 13:15:37+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/range_query/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/range_query/fenwick_tree.test.cpp
- /verify/verify/ds/range_query/fenwick_tree.test.cpp.html
title: verify/ds/range_query/fenwick_tree.test.cpp
---
