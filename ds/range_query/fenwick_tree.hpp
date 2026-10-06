#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
namespace BIT
{
const int N=1000005;
int n;
ll t[N];
void init(int _n)
{
        n=_n;
        for(int i=0;i<=n;i++)
                t[i]=0;
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
}
