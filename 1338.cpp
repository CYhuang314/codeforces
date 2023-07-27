#include<bits/stdc++.h>
#include "lib1338.h"
using namespace std;
typedef long long ll;
const int Size=(int)1e6;
ll st_min[Size+20][25],st_gcd[Size+20][25];
void init(int n,ll c[]){
    for(int i=0;i<n;i++)  st_min[i][0]=st_gcd[i][0]=c[i];
    for(int j=1;j<=20;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<(j-1))][j-1]);
            st_gcd[i][j]=__gcd(st_gcd[i][j-1],st_gcd[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r){
    int k=__lg(r-l);
    return min(st_min[l][k],st_min[r-(1<<k)][k])==__gcd(st_gcd[l][k],st_gcd[r-(1<<k)][k]);
}
/*signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,Q;
    cin>>n;
    For(i,1,n)  cin>>c[i];
    init(n,c);
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
    return 0;
}*/
/*
check:
1.int overflow
2.array out of bound
3.special case(0 or 1)
4.time complexity
*/
