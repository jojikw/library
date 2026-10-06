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
  bundledCode: "#line 2 \"graph/graph.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll=long long;\nnamespace Graph\n{\nconst int MAXV=100005;\ninline\
    \ vector<int>G[MAXV];\ninline vector<int>T[MAXV];\ninline vector<pair<int,ll>>WG[MAXV];\n\
    inline vector<pair<int,ll>>WT[MAXV];\ninline void clr(int n)\n{\n        for(int\
    \ i=0;i<=n;i++)\n                G[i].clear(),T[i].clear(),WG[i].clear(),WT[i].clear();\n\
    }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\nnamespace Graph\n{\nconst int MAXV=100005;\ninline vector<int>G[MAXV];\n\
    inline vector<int>T[MAXV];\ninline vector<pair<int,ll>>WG[MAXV];\ninline vector<pair<int,ll>>WT[MAXV];\n\
    inline void clr(int n)\n{\n        for(int i=0;i<=n;i++)\n                G[i].clear(),T[i].clear(),WG[i].clear(),WT[i].clear();\n\
    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy: []
  timestamp: '2026-10-06 13:15:37+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
