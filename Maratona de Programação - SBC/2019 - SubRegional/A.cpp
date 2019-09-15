#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < int(b);i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define MOD 1000000007
#define endl '\n'
#define mdc(a,b) (__gcd((a),(b)))
#define mmc(a,b) (((a)/mdc(a,b)) * b)
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl

struct Cicle{
	ll x0, y0, r;
};

ll p2(ll x){
	return x*(ll)x;
}
const int MAXN = 100010;
vector<int> adj[MAXN];

bool mark[MAXN];
void dfs(int u){
	mark[u] = true;
	for(int to: adj[u])
		if(!mark[to])
			dfs(to);
	
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	vector<Cicle> v;
	cin >> n >> m >> k;
	for(int i=0; i<k; i++){
		Cicle c;
		cin >> c.x0 >> c.y0 >> c.r;
		v.PB(c);
	}

	for(int j=0; j<k; j++){
		ll a = 1LL;
		ll b = -2LL*v[j].y0;
		ll c = p2(v[j].y0) - p2(v[j].r) + p2(v[j].x0); 
		ll delta = p2(b) - 4LL*a*c;
		
		if(delta >= 0){
			adj[0].PB(j + 4);
			adj[j+4].PB(0);
		}
	}

	for(int j=0; j<k; j++){
		ll a = 1;
		ll b = -2*v[j].y0;
		ll c = p2(v[j].y0) - p2(v[j].r) + p2(n - v[j].x0); 
		ll delta = p2(b) - 4LL*a*c;
		
		if(delta >= 0){
			adj[3].PB(j + 4);
			adj[j+4].PB(3);
		}
	}

	for(int j=0; j<k; j++){
		ll a = 1LL;
		ll b = -2LL*v[j].x0;
		ll c = p2(v[j].x0) - p2(v[j].r) + p2(v[j].y0); 
		ll delta = p2(b) - 4LL*a*c;
		
		if(delta >= 0){
			adj[1].PB(j + 4);
			adj[j+4].PB(1);
		}
	}

	for(int j=0; j<k; j++){
		ll a = 1LL;
		ll b = -2LL*v[j].x0;
		ll c = p2(v[j].x0) - p2(v[j].r) + p2(m - v[j].y0); 
		ll delta = p2(b) - 4LL*a*c;
		
		if(delta >= 0){
			adj[2].PB(j + 4);
			adj[j+4].PB(2);
		}
	}
	
	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			if( p2(v[i].x0 - v[j].x0) + p2(v[i].y0 - v[j].y0) <= p2(v[i].r + v[j].r) ){
				adj[i+4].PB(j+4);
				adj[j+4].PB(i+4);				
			}
		}
	}
	memset(mark, 0, sizeof(mark));
	dfs(0);
	if(mark[1] or mark[3]){
		cout << "N" << endl;
		return 0;
	}
	memset(mark, 0, sizeof(mark));
	dfs(1);
	if(mark[2] or mark[0]){
		cout << "N" << endl;
		return 0;
	}
	memset(mark, 0, sizeof(mark));
	dfs(3);
	if(mark[0] or mark[2]){
		cout << "N" << endl;
		return 0;
	}
	
	cout << "S" << endl;
	
	return 0;
}

/*

10 22 2
4 6 5
6 16 5

10 10 2
3 7 4
5 4 4 

100 100 3
40 50 30
9 90 50 
90 10 5

*/
