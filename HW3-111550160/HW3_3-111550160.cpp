#include <bits/stdc++.h>
//#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); // 好孩子不要查這行
#define pb push_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
//#define X first
//#define Y second
#define eps 0.00000001
#define ist insert
//#define mul(a,b,c) (a%c)*(b%c)%c
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=100005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n;
vector<int> e[N];
int fa[N], h[N];
int dfs(int v,int pre){
    fa[v]=pre;
    if (e[v].size()==1&&v!=1){
        return h[v]=0;
    }
    int mx=0;
    for (int i:e[v])
        if (i!=pre)
            mx=max(mx,dfs(i,v));
    return h[v]=mx+1;

}
void sol(){ 
    cin >>n;
    for (int i=1,x,y;i<n;i++){
        cin >>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++)
        cout <<h[i]<<' '<<fa[i]<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
	srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
	return 0;
}
/*
8
1 2
2 3
3 4
1 5
5 6
5 7
1 8
*/