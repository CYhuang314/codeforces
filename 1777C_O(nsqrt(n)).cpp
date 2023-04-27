#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int Size=100000;
int a[Size+20],cnt[Size+20];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)	cnt[i]=0;
	int check=0,l=1,r=1,ans=Size;
	while(r<=n){
		for(int i=1;i<=min((int)sqrt(a[r]),m);i++){
			if(a[r]%i==0){
				int j=a[r]/i;
				if(!cnt[i]++)	check++;
				if(j<=m){
					if(!cnt[j]++)	check++;
				}
			}
		}
		while(check==m){
			ans=min(ans,a[r]-a[l]);
			for(int i=1;i<=min((int)sqrt(a[l]),m);i++){
				if(a[l]%i==0){
					int j=a[l]/i;
					if(!(--cnt[i]))	check--;
					if(j<=m){
						if(!(--cnt[j]))	check--;	
					}
				}
			}
			l++;
		}
		r++;
	}
	if(ans==Size)	cout<<"-1\n";
	else	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)	solve();
	return 0;
}
/*
check: 
1.int overflow
2.array out of bound
3.special case(0 or 1)
4.time complexity
*/
