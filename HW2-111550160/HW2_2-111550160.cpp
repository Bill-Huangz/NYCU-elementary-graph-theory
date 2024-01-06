#include <bits/stdc++.h>
//#define int long long
#define menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define pi pair<int, int>
#define BE(i) i.begin(),i.end()
#define fi first
#define se second
#define INF 2147483646
#define mkp make_pair
#define ist insert
#define mod 100003
#define N 10005
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC optimize("O2")
using namespace std;
int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}
bool isprime(int k){bool is=1 ; for ( int i = 2 ; i*i <= k ; i++ ) if ( k % i == 0 ) is = 0 ; return k>1?is:0;}
const double PI=acos(-1);
int p[300005];
int boss(int a){return p[a]==a?a:p[a]=boss(p[a]);}
vector<int> e[300005];
int u,len;
void dfs1(int v,int pre,int d){
	if (e[v].size()==1&&pre!=0){
		if (d>len) u=v,len=d;
		return;
	}
	for (int &i:e[v]) if (i!=pre) dfs1(i,v,d+1);
}
int n;
void sol(){
	cin >>n;
	for (int i=2,t,k;i<=n;i++){
		cin >>t>>k;
		e[t].pb(k);
		e[k].pb(t);
	}
	u=len=0;
	dfs1(1,0,0);
	dfs1(u,0,0);
	cout <<len<<"\n";
}
signed main(){
    menhera_chan_is_mine
    int T=1;
    //cin >>T;
    while (T--)
        sol();
 
    return 0;
}