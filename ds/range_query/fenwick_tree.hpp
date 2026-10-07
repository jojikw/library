#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
namespace BIT
{
const int N=1000005;
int n;
ll t[N];
ll t1[N],t2[N];
void init(int _n)
{
        n=_n;
        for(int i=0;i<=n;i++)
                t[i]=0,t1[i]=0,t2[i]=0;
}
void add(int x, ll v)
{
        for(;x<=n;x+=x&-x)
                t[x]+=v;
}
ll qry(int x)
{
        ll ret=0;
        for(;x;x-=x&-x)
                ret+=t[x];
        return ret;
}
ll qry(int l, int r){return qry(r)-qry(l-1);}
int kth(ll k)
{
        int x=0;
        for(int b=1<<20;b;b>>=1)
                if(x+b<=n&&t[x+b]<k)
                        x+=b,k-=t[x];
        return x+1;
}
void add_pt(int x, ll v)
{
        for(int i=x;i<N;i+=i&-i)
                t1[i]+=v,t2[i]+=v*x;
}
void add_range(int l, int r, ll v)
{
        add_pt(l,v);
        add_pt(r+1,-v);
}
ll qry_range(int x)
{
        ll s1=0,s2=0;
        for(int i=x;i;i-=i&-i)
                s1+=t1[i],s2+=t2[i];
        return s1*(x+1)-s2;
}
ll qry_range(int l, int r){return qry_range(r)-qry_range(l-1);}
}
namespace BIT2D
{
const int N=2005;
ll t[N][N];
int n,m;
void init(int _n, int _m)
{
        n=_n;
        m=_m;
        for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                        t[i][j]=0;
}
void add(int x, int y, ll v)
{
        for(int i=x;i<=n;i+=i&-i)
                for(int j=y;j<=m;j+=j&-j)
                        t[i][j]+=v;
}
ll qry(int x, int y)
{
        ll s=0;
        for(int i=x;i>0;i-=i&-i)
                for(int j=y;j>0;j-=j&-j)
                        s+=t[i][j];
        return s;
}
ll qry_rect(int x1, int y1, int x2, int y2){return qry(x2,y2)-qry(x1-1,y2)-qry(x2,y1-1)+qry(x1-1,y1-1);}
}
