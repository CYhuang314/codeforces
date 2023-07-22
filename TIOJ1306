#include<bits/stdc++.h>
using namespace std;
#define int long long

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
const int Size=(int)1e4;
int pi[Size+20];
int match(const string& A, const string& B)
{
    int ans=0;
    pi[0]=-1;
    pi[1]=0;
    for(int i=1,j=0;i<B.size()-1;pi[++i]=++j){
        while(j!=-1&&B[i]!=B[j]) j=pi[j];
    }
    for(int i=0,j=0;i-j+B.size()<=A.size();i++,j++){
        while(j!=-1&&A[i]!=B[j]) j=pi[j];
        if (j==B.size()-1){
            ans++;
            j=pi[j];
        }
    }
    return ans;
}
void solve(){
    string T;
    cin>>T;
    int Q;
    cin>>Q;
    while(Q--){
        string P;
        cin>>P;
        cout<<match(T,P)<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}
/*
check:
1.int overflow
2.array out of bound
3.special case(0 or 1)
4.time complexity
*/
