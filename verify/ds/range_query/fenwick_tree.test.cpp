#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#include "ds/range_query/fenwick_tree.hpp"
int n,q;
void solve()
{
        cin>>n>>q;
        BIT::init(n);
        for(int i=1;i<=n;i++)
        {
                ll x;cin>>x;
                BIT::add(i,x);
        }
        while(q--)
        {
                int t,a,b;cin>>t>>a>>b;
                if(t==0)
                        BIT::add(a+1,b);
                else
                        cout<<BIT::qry(a+1,b)<<'\n';
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
