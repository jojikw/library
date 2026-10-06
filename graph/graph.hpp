#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
namespace Graph
{
const int MAXV=100005;
inline vector<int>G[MAXV];
inline vector<int>T[MAXV];
inline vector<pair<int,ll>>WG[MAXV];
inline vector<pair<int,ll>>WT[MAXV];
inline void clr(int n)
{
        for(int i=0;i<=n;i++)
                G[i].clear(),T[i].clear(),WG[i].clear(),WT[i].clear();
}
}
