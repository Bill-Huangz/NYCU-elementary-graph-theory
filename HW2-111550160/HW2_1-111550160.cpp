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

int n,start;
vector<pair<int,string>> e[25];
string ans;
string mer[20][20];
string remin(string a,string b){
	if (a.length()!=b.length()) return a.length()<b.length()?a:b;
	return a<b?a:b;
}
void dfs(int cur,string s,int v){
	if (1.0*(clock()-start)/CLOCKS_PER_SEC>=0.9){
		cout <<ans<<'\n';
		exit(0);
	}
	if (s.length()>ans.length()) return;
	if (cur==((1<<n)-1)){
		ans=remin(ans,s);
		return;
	}
	for (auto [x,y]:e[v]){
		if ((cur&(1<<x))==0){
			dfs(cur|(1<<x),s+y,x);	
		}
	}
}
void sol(){
	cin >>n;
	string s[25];
	for (int i=0;i<n;i++) cin >>s[i];
	vector<string> vc;
	for (int i=0;i<n;i++){
		int ok=0;
		for (int j=0;j<n;j++){
			if (i!=j&&s[i]!=s[j]){
				for (int k=s[i].length();k<=s[j].length();k++){
					if (s[j].substr(k-s[i].length(),s[i].length())==s[i]){
						ok=1;
					}
				}
			}
			
		}
		if (!ok) vc.pb(s[i]);
	}
	sort(ALL(vc));
	n=vc.size();
	for (int i=0;i<n;i++) cerr<<vc[i]<<'\n';
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j) continue;
			else {
				//c[i][j]=0;
				int x=vc[i].length(),y=vc[j].length();
				mer[i][j]=vc[j];
				for (int len=1;len<=min(x,y);len++)
					if (vc[i].substr(x-len,len)==vc[j].substr(0,len))
						/*c[i][j]=len,*/mer[i][j]=vc[j].substr(len,y-len);
				e[i].pb(make_pair(j,mer[i][j]));
			}
		}
	}
	for (int i=0;i<n;i++){
		sort(ALL(e[i]),[](pair<int,string> a,pair<int,string> b){
			if (a.se.length()!=b.se.length()) return a.se.length()<b.se.length();
			return a.se<b.se;
		});
	}
	ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int i=0;i<n;i++){
		dfs((1<<i),vc[i],i);
	}
	cout <<ans<<"\n";

}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
	start=clock();
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
	return 0;
}
/*
4
i
love
saito
asuka
*/
/*
11
genshin
impact
start
hee
hee
hee
i
am
a
klee
player
*/