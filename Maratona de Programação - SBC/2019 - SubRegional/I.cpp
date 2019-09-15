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
const int MAXQ = 100010;
const int MAXN = 404;
struct Query{
	int a, b, k, id;
};

vector<Query> v0;
vector<Query> k0;
vector<Query> v1;
vector<Query> k1;
ll dist[MAXN][MAXN];
pii temp[MAXN];
int kesimo[MAXN];

vector<pii> adj[MAXN];
ll ans[MAXQ];

int main(){
	memset(dist, 0x3f, sizeof(dist));	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> temp[i].F;
		temp[i].S = i;
	}
	sort(temp+1, temp+n+1);
	kesimo[1] = 1;
	for(int i=2; i<=n; i++){
		if(temp[i-1].F == temp[i].F)
			kesimo[i] = kesimo[i-1];
		else
			kesimo[i] = kesimo[i-1] + 1;
	}	
	
	for(int i=0; i<m; i++){
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].PB(pii(b, d));
		adj[b].PB(pii(a, d));
		dist[a][b] = d;
		dist[b][a] = d;
	}
	
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		Query q1;
		int t;
		cin >> q1.a >> q1.b >> q1.k >> t;
		q1.id = i;
		if(t == 0)
			v0.PB(q1);
		else
			v1.PB(q1);
	}
	

	sort(all(v0), [&](Query a, Query b){
		return a.k < b.k;
	});
	int iT = 0;

	for(int i=0; i<(int)v0.size(); i++){
		Query q1 = v0[i];
		while( (iT <= n) and ( kesimo[iT] <= q1.k) ){
			int u = temp[iT].S;
			iT++;

			for(int a=1; a<=n; a++)
				for(int b=1; b<=n; b++)
					if(dist[a][u]<INFLL and dist[u][b]<INFLL)
						dist[a][b] = min(dist[a][b], dist[a][u] + dist[u][b]);
		}
		
		if(dist[q1.a][q1.b] >= INFLL)
			ans[q1.id] = -1;
		else
			ans[q1.id] = dist[q1.a][q1.b];
	}

	reverse(temp+1, temp+n+1);
	kesimo[1] = 1;
	for(int i=2; i<=n; i++){
		if(temp[i-1].F == temp[i].F)
			kesimo[i] = kesimo[i-1];
		else
			kesimo[i] = kesimo[i-1] + 1;
	}	
	memset(dist, 0x3f, sizeof(dist));	
	for(int u=1; u<=n; u++){
		for(pii p: adj[u]){
			dist[u][p.F] = p.S;
			dist[p.F][u] = p.S;			
		}
	}
	sort(all(v1), [&](Query a, Query b){
		return a.k < b.k;
	});
	iT = 0;

	for(int i=0; i<(int)v1.size(); i++){
		Query q1 = v1[i];
		while( (iT <= n) and ( kesimo[iT] <= q1.k) ){
			int u = temp[iT].S;
			iT++;
			for(int a=1; a<=n; a++)
				for(int b=1; b<=n; b++)
					if(dist[a][u]<INFLL and dist[u][b]<INFLL)
						dist[a][b] = min(dist[a][b], dist[a][u] + dist[u][b]);
		}
		
		if(dist[q1.a][q1.b] >= INFLL)
			ans[q1.id] = -1;
		else
			ans[q1.id] = dist[q1.a][q1.b];
	}
	
	for(int i=0; i<q; i++)
		cout << ans[i] << endl;
		
	return 0;
}

/*
7 9
-53 -180 456 420 -210 15 150
1 2 2
1 3 1
2 3 4
2 4 2
2 5 5
3 4 6
6 4 10
4 5 4
3 7 2
4
1 5 2 1
1 2 1 1
5 6 1 0
1 7 2 1


6 5
5 10 20 10 10 8
1 2 5
2 3 5
3 4 5
4 5 5
5 6 5
4
1 6 2 1
1 6 1 1
4 5 1 0 
2 4 1 1

*/
