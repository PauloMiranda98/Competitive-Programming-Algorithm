#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl

#define F first
#define S second
#define PB push_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define for1n(i, n) for(int i = 1; i <= int(n); i++)
#define for1r(i, n) for(int i = int(n); i >= 1; i--)
#define ms(x, v) memset((x), (v), sizeof(x))
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

#define MAXN 300010


struct SetClear{

	struct cmp{
		bool operator()(pii a, pii b){
			return a.S < b.S;		
		}
	};

	set<pii, cmp> st;
	int n;
	int ans;

	SetClear(int _n){
		n = _n;
		ans = n;
	}
	
	void Set(int a, int b){
		auto p = st.upper_bound({0, a-1});

		if( (p == st.end()) or (p->first > b) ){
			
		}else{
			int x = p->first;
			int y = p->second;
				
			ans += (y-x+1);
			p = st.erase(p);
		
			if(x<=(a-1)){						
				ans -= (a-x);					
				st.insert({x, a-1});
			}
			if( (b+1) <= y){
				ans -= (y-b);
							
				st.insert({b+1, y});					
			}

			
			while( (p != st.end()) and (p->first <= b) ){
				x = p->first;
				y = p->second;

				ans += (y-x+1);

				if(y > b){
					ans -= (y-b);					
					
					st.erase(p);
					st.insert({b+1, y});

					break;
				}else{
					p = st.erase(p);
				}
			}
			
		}
		
	}
	
	void Clear(int a, int b){
		auto p = st.upper_bound({0, a-1});

		if( (p == st.end()) or (p->first > b) ){
			ans -= (b-a+1);
			st.insert({a, b});
		}else{
			int x = p->first;
			int y = p->second;

			ans += (y-x+1);
			p = st.erase(p);

			a = min(x, a);
			b = max(y, b);
				
			while( (p!=st.end()) and (p->first <= b) ){
				x = p->first;
				y = p->second;
				ans += (y-x+1);

				a = min(x, a);
				b = max(y, b);
				
				p = st.erase(p);
			}
			
			ans -= (b-a+1);
			st.insert({a, b});									
		}		
	}
	
	int Count(){
		return ans;
	}

};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;	
	cin >> n >> m;

	SetClear sc(n);
	
	for(int i=0; i<m; i++){
		int a, b, op;
		
		cin >> a >> b >> op;	

		if(op == 1){
			sc.Clear(a, b);
		}else{
			sc.Set(a, b);			
		}
		
		cout << sc.Count() << endl;
	}
	
	return 0;
	
}
