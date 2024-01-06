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
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC optimize("O3")

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


int e[15][15];
int ee[15][15];
int deg[15];
int n,m;
bool testk5(){
    // memset(deg,0,sizeof(deg));
    // for (int i=0;i<15;i++)
    //     for (int j=0;j<15;j++)
    //         e[i][j]=ee[i][j];
    
    // for (int i=0;i<n;i++)
    //     deg[i]=accumulate(e[i],e[i]+15,0);

    vector<int> vc;
    for(int i=0;i<n;i++){
        if(deg[i]==4) vc.pb(i);
    }
    if(vc.size()!=5) return 0;
    string XXX(n-5,'0'); string YYY(5,'1');
    string s=XXX+YYY; 
    // cout <<"1. k5\n";
    while (1){
        int eri=-1;
        for (int i=0;i<n;i++){
            if (deg[i]==2){
                eri=i;
                int x=-1,y=-1;
                for (int j=0;j<n;j++){
                    if (e[eri][j]){
                        x==-1?x=j:y=j;
                    }
                    
                }
                e[x][y]=e[y][x]=1;
                    e[x][eri]=0;
                    e[eri][x]=0;
                    e[y][eri]=0;
                    e[eri][y]=0;
                    deg[eri]=0;
            }
        }
        // cout <<eri<<' ';
        if (eri==-1) break;        
    }
    
    int tmp = 0;
    for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            if(e[vc[i]][vc[j]]){
                tmp++;
            }
        }
    }
    if (tmp==20) return 1;
    else return 0;
}

bool testk33(){
    vector<int> vc;
    // memset(deg,0,sizeof(deg));
    // for (int i=0;i<15;i++)
    //     for (int j=0;j<15;j++)
    //         e[i][j]=ee[i][j];
    
    // for (int i=0;i<n;i++)
    //     deg[i]=accumulate(e[i],e[i]+15,0);

    for(int i =0 ;i<n;i++){
        if(deg[i]==3)vc.pb(i);
    }
    if(vc.size()!=6)return 0;

    while (1){
        int eri=-1;
        for (int i=0;i<n;i++){
            if (deg[i]==2){
                eri=i;
                int x=-1,y=-1;
                for (int j=0;j<n;j++){
                    if (e[eri][j]){
                        x==-1?x=j:y=j;
                    }
                }
                e[x][y]=e[y][x]=1;
                e[x][eri]=0;
                e[eri][x]=0;
                e[y][eri]=0;
                e[eri][y]=0;
                deg[eri]=0;
            }
        }
        // cout <<eri<<' ';
        if (eri==-1) break;        
    }

    vector<int> is_down;
    vector<int> is_up;
    is_up.pb(vc[0]);
    for(int i = 1 ;i<6;i++){
        if(e[vc[0]][vc[i]])is_down.pb(vc[i]);
        else is_up.pb(vc[i]);
    }
    if(is_up.size()!=3||is_down.size()!=3)return false;
    int temp = 0;
    for(int i :is_up){
        for(int j:is_down){
            if(e[i][j])temp++;
        }
    }
    if(temp==9)return 1;
    return 0;
}
// bool _sol(){
    
    
//     vc.clear();
//     // cout <<"2. k5\n";
//     if (n<6){
        
//         return 1;
//     }
    


//     // cout <<"3. k33\n";
    
//     string XX(n-6,'0'); string YY(6,'1');
//     s=XX+YY; 
//     do{
//         vector<int> tmp;
//         for (int i=0;i<n;i++)
//             if (s[i]=='1')
//                 tmp.pb(i);
//         if (testk33(tmp)){
//             return 0;
//         }
//     }while (next_permutation(ALL(s)));
//     // cout <<"4. k33\n";
//     return 1;

// }   

void sol(){
    cin >>n>>m;
    memset(deg,0,sizeof(deg));
    memset(e,0,sizeof(e));
    memset(ee,0,sizeof(ee));
    vector<pii> E;
    for (int i=1,x,y;i<=m;i++){
        cin >>x>>y;
        x--, y--;
        E.pb({x,y});
    }

    

    for (int bit=1;bit<(1<<m);bit++){
        // cout <<bit<<'\n';
        //if (bitCount(bit)<9) continue;
        memset(deg,0,sizeof(deg));
        memset(e,0,sizeof(e));
        memset(ee,0,sizeof(ee));
        for (int i=0;i<m;i++)
            if (bit&(1<<i)){
                auto [x,y]=E[i];
                e[x][y]=1;
                deg[x]++;
                e[y][x]=1;
                deg[y]++;
            }

        if (testk5()||testk33()){
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
}
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    //srand(time(NULL));
    int _=1;
    
    cin >>_;
    while (_--) sol();
    return 0;
}
/*
1
5 1005
5 9 8 8 3
1 11 9 6 3

3 600
3 4 5
7 5 6
*/
