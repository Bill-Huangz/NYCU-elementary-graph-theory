#include <bits/stdc++.h>
#define int long long
#define menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pi pair<int, int>
#define BE(i) i.begin(),i.end()
#define fi first
#define se second
#define INF 2147483646
#define mkp make_pair
#define ist insert
#define mod 100003
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC optimize("O2")
using namespace std;
int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}
bool isprime(int k){bool is=1 ; for ( int i = 2 ; i*i <= k ; i++ ) if ( k % i == 0 ) is = 0 ; return k>1?is:0;}
const double PI=acos(-1);
int n,m;
vector<int> e[200005];
bool is;
int clr[200005];
void dfs(int v,int c){
	if (clr[v]!=0){
		if (clr[v]!=c) is=0;
		return;
	}
	clr[v]=c;
	for (int &i:e[v]) dfs(i,1+(c==1));
}
void sol(){
	cin >>n>>m;
	for (int i=0,a,b;i<m;i++){
		cin >>a>>b;
		e[a].pb(b);
		e[b].pb(a);
	}
	is=1;
	for (int i=1;i<=n;i++){
		if (clr[i]==0){
			dfs(i,1);
		}
	}
	if (!is) cout <<"No\n";
	else cout <<"Yes\n";
}
signed main(){
    menhera_chan_is_mine
    int T=1;
    //cin >>T;
    while (T--)
        sol();
 
    return 0;
}