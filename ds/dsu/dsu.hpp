#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
namespace DSU
{
const int N=200005;
int fa[N],sz[N];
void init(int n)
{
        for(int i=1;i<=n;i++)
                fa[i]=i,sz[i]=1;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool merge(int x, int y)
{
        x=find(x);
        y=find(y);
        if(x==y)
                return false;
        if(sz[x]<sz[y])
                swap(x,y);
        fa[y]=x;
        sz[x]+=sz[y];
        return true;
}
struct Pot
{
int p[N],sz[N];
ll val[N];
int mod=998244353;
ll norm(ll x){return (x%mod+mod)%mod;}
void init(int n, int _mod=998244353)
{
        mod=_mod;
        for(int i=1;i<=n;i++)
        {
                p[i]=i;
                sz[i]=1;
                val[i]=0;
        }
}
int find(int u)
{
        if(p[u]==u)
                return u;
        int r=find(p[u]);
        val[u]=(val[u]+val[p[u]])%mod;
        return p[u]=r;
}
bool unite(int u, int v, ll w)
{
        w=norm(w);
        int ru=find(u),rv=find(v);
        if(ru==rv)
                return norm(val[u]-val[v])==w;
        if(sz[ru]<sz[rv])
        {
                p[ru]=rv;
                val[ru]=norm(val[v]-val[u]+w);
                sz[rv]+=sz[ru];
        }
        else
        {
                p[rv]=ru;
                val[rv]=norm(val[u]-val[v]-w);
                sz[ru]+=sz[rv];
        }
        return true;
}
pair<bool,ll> diff(int u, int v)
{
        if(find(u)!=find(v))
                return {false,0};
        return {true,norm(val[u]-val[v])};
}
};
struct Rollback
{
int n,comps;
vector<int> p,sz;
struct Op
{
int u,v;
bool merged;
};
vector<Op> his;
Rollback(int n=0):n(n),comps(n),p(n+1),sz(n+1,1){iota(p.begin(),p.end(),0);}
int find(int x)
{
        while(x!=p[x])
                x=p[x];
        return x;
}
bool unite(int a, int b)
{
        a=find(a);
        b=find(b);
        if(a==b)
        {
                his.push_back({a,b,false});
                return false;
        }
        if(sz[a]<sz[b])
                swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        comps--;
        his.push_back({a,b,true});
        return true;
}
int snapshot(){return his.size();}
void rollback(int t)
{
        while((int)his.size()>t)
        {
                auto [a,b,m]=his.back();
                his.pop_back();
                if(m)
                {
                        sz[a]-=sz[b];
                        p[b]=b;
                        comps++;
                }
        }
}
};
}
