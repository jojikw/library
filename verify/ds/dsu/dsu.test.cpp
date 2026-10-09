#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#include "ds/dsu/dsu.hpp"
void solve()
{
        int n,q;cin>>n>>q;
        DSU::init(n);
        while(q--)
        {
                int t,u,v;cin>>t>>u>>v;
                u++;
                v++;
                if(t==0)
                        DSU::merge(u,v);
                else
                        cout<<(DSU::find(u)==DSU::find(v))<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
