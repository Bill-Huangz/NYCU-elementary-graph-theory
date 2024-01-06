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
//  #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC optimize("O2")
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

struct Edge{
    int u,v,w;
    bool operator<(const Edge& rh){
        return w<rh.w;
    }
} e[2*N];
int p[N],a[N];
int mn[N];
int n,m;
int boss(int v){return v==p[v]?v:p[v]=boss(p[v]);}
void sol(){ 
    cin >>n>>m;
    int vx=1,mn=2147483647;
    for (int i=1;i<=n;i++) {
        cin >>a[i];
        if (mn>a[i]){
            mn=a[i];
            vx=i;
        }
    }
    for (int i=0;i<m;i++){
        cin >>e[i].u>>e[i].v>>e[i].w;
    }
    for (int i=1;i<=n;i++)
        if (i!=vx)
            e[m++]={vx,i,a[vx]+a[i]};
    sort(e,e+m);
    for (int i=1;i<=n;i++) p[i]=i;
    ll ans=0;
    for (int i=0;i<m;i++){
        int x=boss(e[i].u),y=boss(e[i].v);
        if (x!=y){  
            //cout <<x<<' '<<y<<'\n';
            p[x]=y;
            ans+=e[i].w;
        }
    }
    cout <<ans<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
	srand(time(NULL));
    int _=1;
    cin >>_;
    while (_--) sol();
	return 0;
}