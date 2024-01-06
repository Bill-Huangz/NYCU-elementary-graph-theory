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


int n,m,tst=1;
vector<int> e[N];
int low[N],dfn[N],cut[N];
void tarjan(int v,int pre){
    dfn[v]=low[v]=tst++;
    int son=0;
    for (int &i:e[v]){
        if (!dfn[i]){
            son++;
            tarjan(i,v);
            low[v]=min(low[v],low[i]);
            if (low[i]>=dfn[v]) cut[v]=1;
        }
        else low[v]=min(low[v],dfn[i]);
    }
    if (pre==-1&&son==1) cut[v]=0;
}
void sol(){ 
    cin >>n>>m;
    for (int i=0,x,y;i<m;i++){
        cin >>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    int s=0;
    for (int i=1;i<=n;i++)
        if (!dfn[i])
            tarjan(i,-1);
    for (int i=1;i<=n;i++)
        if (cut[i])
            s++;
    cout <<s<<"\n";
    for (int i=1;i<=n;i++)
        if (cut[i])
            cout <<i<<' ';

    cout <<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
	srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
	return 0;
}
