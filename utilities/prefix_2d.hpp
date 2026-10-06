#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
namespace PREF2D
{
const int N=1005;
ll t[N][N];
ll d[N][N];
void build(int n, int m, int a[N][N])
{
        for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                        t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+a[i][j];
}
ll qry(int x1, int y1, int x2, int y2){return t[x2][y2]-t[x1-1][y2]-t[x2][y1-1]+t[x1-1][y1-1];}
void add(int x1, int y1, int x2, int y2, ll v)
{
        d[x1][y1]+=v;
        d[x1][y2+1]-=v;
        d[x2+1][y1]-=v;
        d[x2+1][y2+1]+=v;
}
void rebuild(int n, int m)
{
        for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                        d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
}
}
