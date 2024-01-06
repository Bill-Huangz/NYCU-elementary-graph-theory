#include <bits/stdc++.h>
#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
#define eps 0.00000001
#define ist insert
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=200005;
const int M=100005;
const int MOD=998244353;//1000000007;
const int INF=(1LL<<40);//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

int n,m,K;
vector<pii> e[N];
int d[3][N];
void dij(int S,int ii){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	d[ii][S]=0;
	pq.push({0,S});
	while (pq.size()){
		auto [c,v]=pq.top();pq.pop();
		if (d[ii][v]<c) continue;
		for (auto [x,y]:e[v]){
			if (d[ii][x]>c+y){
				d[ii][x]=c+y;
				pq.push({c+y,x});
			}
		}
	}
}
void dijj(int ii){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for (int i=1;i<=n;i++)
		pq.push({d[ii][i],i});
	while (pq.size()){
		auto [c,v]=pq.top();pq.pop();
		if (d[ii][v]<c) continue;
		for (auto [x,y]:e[v]){
			if (d[ii][x]>c+y){
				d[ii][x]=c+y;
				pq.push({c+y,x});
			}
		}
	}
}
void sol(){
    cin >>n>>m>>K;
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=0,x,y,c;i<m;i++){
		cin >>x>>y>>c;
		e[y].pb({x,c});
	}
	for (int i=1;i<=n;i++)
		d[0][i]=d[1][i]=d[2][i]=INF;
	dij(1,0);
	dij(n,1);
	if (K==1){
		for (int i=1;i<=n;i++)
			cout <<(d[0][i]==INF?-1:d[0][i])<<" \n"[i==n];
		return;
	}
	for (int i=1;i<=n;i++)
		d[2][i]=min(d[2][i],d[0][i]+d[1][i]);
	dijj(2);
	for (int i=1;i<=n;i++)
		cout <<(d[2][i]>=INF?-1:d[2][i])<<" \n"[i==n];
}
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine
    //srand(time(NULL));
    int _=1,__;
    cin >>_>>__;
    while (_--) sol();
    //while (cin >>n&&n) sol();

    return 0;
}
