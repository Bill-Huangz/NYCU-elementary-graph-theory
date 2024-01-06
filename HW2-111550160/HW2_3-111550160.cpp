#include <bits/stdc++.h>
// #define int long long
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
const int N=1000005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int isJoint[N];
int deg[N],ned[N];
int val[N];
int n,m,L,R,len;
vector<int> e[N];
vector<int> rout,res;
bool Rout[N];
void dfs1(int v,int pre,int d){
	if (isJoint[v]){
		if (d>len) R=v,len=d;
	}
	for (int i:e[v]) if (i!=pre&&deg[i]>=0) dfs1(i,v,d+1);
}

void dfs2(int v,int pre,int d){
	if (isJoint[v]){
		if (d>len) L=v,len=d;
	}
	for (int i:e[v]) if (i!=pre&&deg[i]>=0) dfs2(i,v,d+1);
}
bool dfs3(int v,int pre){
    if (v==R){
        return 1;
    }
    if (deg[v]<0&&e[v].size()==1) return 0;
    for (int i:e[v]){
        if (i!=pre){
            rout.pb(i);
            if (dfs3(i,v)) return 1;
            rout.pop_back();
        }
    }
    return 0;
}

void sol(){
    cin >>n;
    for (int i=1,x,y;i<n;i++){
        cin >>x>>y;
        e[x].pb(y);
        e[y].pb(x);
        deg[x]++;deg[y]++;
    }
    queue<int> q;
    for (int i=0;i<n;i++){
        val[i]=1;
        if (deg[i]==3) 
            isJoint[i]=1;
        if (deg[i]==1)
            deg[i]-=1,q.push(i);
        //if (isJoint[i]) cout <<i<<' ';
    }
    //cout <<'\n';
    while (q.size()){
        int v=q.front();q.pop();
        //cout <<v<<' ';
        
        for (int i:e[v]){
            if (deg[i]>0){
                val[i]+=val[v];
            }
            deg[i]--;
            
            if (!isJoint[i]&&deg[i]==1)
               deg[i]=-1, q.push(i);
        }
    } 
    //cout <<'\n';
    for (L=0;L<n;L++){
        if (isJoint[L]) break;
    }
    //for (int i=0;i<n;i++)
    //    cout <<val[i]<<' ';
    len=0;
    // cout <<L<<" ";
    dfs1(L,-1,0);
    // cout <<R<<'\n';
    len=0;
    dfs2(R,-1,0);
    // cout <<L<<'\n';
    rout.pb(L);
    dfs3(L,-1);
    //for (int i:rout) cout <<i<<' '; cout <<'\n';
    vector<int> l,r,mid;
    for (int i:rout){
        if (i==L) {
            for (int j:e[i]){
                if (find(ALL(rout),j)==rout.end()){
                    l.pb(val[j]);
                }
            }   
        }
        else if (i==R) {
            for (int j:e[i]){
                if (find(ALL(rout),j)==rout.end()){
                    r.pb(val[j]);
                }
            }
        }
        else if (isJoint[i]){
            for (int j:e[i]){
                if (find(ALL(rout),j)==rout.end()){
                    mid.pb(val[j]);
                }
            }
        }
    }
    cin >>m;
    for (int i=0;i<m;i++) cin >>ned[i];
    if ((m-2)!=mid.size()){
        cout <<"NO\n";
        return;
    }
    int ok=1,fl=(find(ALL(l),ned[0])!=l.end()),fr=(find(ALL(r),ned[m-1])!=r.end());
    if (fl&fr){
        for (int i=1;i<m-1;i++){
            if (mid[i-1]!=ned[i]){
                ok=0;
            }
        }
    }
    else ok=0;
    if (ok){
        cout <<"YES\n";
        return;
    }
    ok=1,fl=(find(ALL(r),ned[0])!=r.end()),fr=(find(ALL(l),ned[m-1])!=l.end());
    reverse(ALL(mid));
    if (fl&fr){
        for (int i=1;i<m-1;i++){
            if (mid[i-1]!=ned[i]){
                ok=0;
            }
        }
    }
    else ok=0;
    if (ok){
        cout <<"YES\n";
        return;
    }
    else {
        cout <<"NO\n";
    }

    /*
    for (int i:l) cout <<i<<' '; cout <<'\n';
    for (int i:mid) cout <<i<<' '; cout <<'\n';
    for (int i:r) cout <<i<<' '; cout <<'\n';
    */
}   
signed main(){
    //Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}