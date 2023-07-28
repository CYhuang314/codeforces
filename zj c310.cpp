#include<bits/stdc++.h>
using namespace std;
//#define int long long

#define For(i,a,b) for(int i=a;i<=b;i++)

typedef pair<int,int> pii;
#define F first
#define S second

typedef vector<int> vi;
#define pb push_back
#define ft front()
#define bk back()
#define tp top()
#define lb lower_bound
#define ub upper_bound
const int Size=100000;
int _t;
int a[Size+20],bit[2*Size+20],in[Size+20],out[Size+20];
vi adj[Size+20];
void dfs(int u){
    in[u]=++_t;
    for(auto v:adj[u])  dfs(v);
    out[u]=++_t;
}
int lowbit(int x){
    return x&(-x);
}
void modify(int x,int N,int k){
    while(x<=N){
        bit[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x){
    int sum=0;
    while(x){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    For(i,1,n)  a[i]=1;
    For(i,1,2*n)    bit[i]=lowbit(i);
    For(i,1,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    dfs(1);
    int q;
    cin>>q;
    while(q--){
        int c,x;
        cin>>c>>x;
        if(c==1){
            modify(in[x],2*n,(1^a[x])-a[x]);
            modify(out[x],2*n,(1^a[x])-a[x]);
            a[x]^=1;
        }
        else    cout<<(query(out[x])-query(in[x]-1))/2<<"\n";
    }
    return 0;
}
/*
check:
1.int overflow
2.array out of bound
3.special case(0 or 1)
4.time complexity
5.try to change dimension in array!!!
*/
