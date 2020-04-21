#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int v[500010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;

	ll ans=0;
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	int s = 1;
	for(int i=n; i>=1; i--){
		ans += s*v[i];
		s = s*-1;
	}
	int q;
	cin >> q;
	while(q--){
		int a, b, c;
		cin >> a >> b >> c;
				
		int even = (b-a+1)/2;
		int odd = (b-a+1)/2;
		if((b-a+1)%2==1){
			if(a%2 == 0)
				even++;
			else
				odd++;
		}
		assert(even + odd == (b-a+1));
		if(n%2 == 0){
			ans += (even-odd)*c;
		}else{
			ans += (odd-even)*c;
		}				
		cout << ans << endl;
	}
	return 0;
}
