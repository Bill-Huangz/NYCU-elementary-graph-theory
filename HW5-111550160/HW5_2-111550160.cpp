#include <bits/stdc++.h>
#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
#define bitCount(i) __builtin_popcount(i)
//#define X first
//#define Y second
#define eps 0.00000001
#define ist insert
//#define mul(a,b,c) (a%c)*(b%c)%c
// #pragma GCC optimize("Ofast","inline","-ffast-math")
// #pragma GCC optimize("O3")

//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=100005;
const int M=505;
const int MOD=1000000007;//998244353;
const ll INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
struct Dinic{
    static const int N=2E3+5;
    static const int INF=1E9+7;
    struct Edge{
        int to,cap,rev;
        Edge(){};
        Edge(int _to,int _cap,int _rev):to(_to),cap(_cap),rev(_rev){}
    };
    vector<Edge> G[N];
    void add_edge(int from,int to,int cap){
        G[from].push_back(Edge(to,cap,(int)G[to].size()));
        G[to].push_back(Edge(from,0,(int)G[from].size()-1));
    }
    int n,s,t;
    void init(int _n,int _s,int _t){
        n=_n,s=_s,t=_t;
        for(int i=0;i<=n;++i)
            G[i].clear();
    }
    int level[N],iter[N];
    void bfs(){
        memset(level,-1,sizeof(level));
        level[s]=0;
        queue<int> que;que.push(s);
        while(!que.empty()){
            int tmp=que.front();que.pop();
            for(Edge e:G[tmp]){
                if(e.cap>0&&level[e.to]==-1){
                    level[e.to]=level[tmp]+1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int now,int flow){
        if(now==t) return flow;
        for(int &i =iter[now];i<(int)G[now].size();++i){
            Edge &e =G[now][i];
            if(e.cap>0&&level[e.to]==level[now]+1){
                int ret=dfs(e.to,min(flow,e.cap));
                if(ret>0){
                    e.cap-=ret;
                    G[e.to][e.rev].cap+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    int flow(){
        int ret=0;
        while(true){
            bfs();
            if(level[t]==-1) break;
            memset(iter,0,sizeof(iter));
            int tmp;
            while((tmp=dfs(s,INF))>0)
                ret+=tmp;
        }
        return ret;
    }
} flow;

vector<pii> E;
int n,m;
void sol(){
    cin >>n>>m;
    for (int i=0,x,y;i<m;i++){
        cin >>x>>y;
        E.pb({x,y});
    }
    int ans=INF;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            if (i!=j){
                flow.init(n,i,j);
                for (auto [x,y]:E){
                    flow.add_edge(x,y,1);
                    flow.add_edge(y,x,1);
                }
                ans=min(ans,flow.flow());
            }
    }
    cout <<ans<<'\n';
}
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    //srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}
