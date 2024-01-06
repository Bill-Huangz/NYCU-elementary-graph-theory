#include <bits/stdc++.h>
//#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
const int N=1005;
const int M=505;
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n,m;
int e[N][N];
int in[N],out[N];
void sol(){
    cin >>n>>m;
    for (int i=1,w,x,y;i<=m;i++){
        cin >>x>>y>>w;
        e[x][y]=w;
        in[y]++;out[x]++;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout <<e[i][j]<<' ';
        cout <<'\n';
    }
    for (int i=1;i<=n;i++) cout <<in[i]<<' '<<out[i]<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    //while (cin >>n&&n) sol();
    return 0;
}