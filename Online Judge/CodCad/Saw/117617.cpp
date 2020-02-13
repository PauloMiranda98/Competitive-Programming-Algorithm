#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007ll

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

#define cind(a) scanf("%lf", &a)
#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

#define coutd(a) printf("%lf", a)
#define coutdl(a) printf("%lf\n", a)
#define coutc(a) printf("%c", a)
#define coutcl(a) printf("%c\n", a)
#define coutll(a) printf("%lld", a)
#define coutlll(a) printf("%lld\n", a)

#define couti(a) printf("%ld", a)
#define coutil(a) printf("%ld\n", a)
#define cout2i(a, b) printf("%ld %ld\n", a, b)
#define cout3i(a, b, c) printf("%ld %ld %ld\n", a, b, c)
#define cout4i(a, b, c, d) printf("%ld %ld %ld %ld\n", a, b, c, d)
#define cout5i(a, b, c, d, e) printf("%ld %ld %ld %ld %ld\n", a, b, c, d, e)

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

ll memo[1010][1010];

ll pd(int i, int j){
	if(memo[i][j] != -1)
		return memo[i][j];
	
	if(i < 1+2*j)
		return memo[i][j] = 0ll;
		
	if(j == 0){
		if(i == 1)
			return memo[i][j] = 1ll;
		if(i == 2)
			return memo[i][j] = 2ll;

		return memo[i][j] = (2ll*pd(i-1, j))%MOD;	
	}
	
	return memo[i][j] = (((pd(i-1, j)*(2ll + 2*j))%MOD) + ((pd(i-1, j-1)*((i-1) - 2ll*(j-1) - 1ll))%MOD))%MOD;
}

int main(){	
	
	memset(memo, -1, sizeof(memo));
	
	int n, k;
	cin >> n >> k;
	
	cout << pd(n, k) << endl;
		
	return 0;
}
