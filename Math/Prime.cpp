#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll ns;
bitset<10000010> bs;
vector<ll> primes;         

void sieve(ll l) {
	ns = l+1;
	bs.set();                  
	bs[0] = bs[1] = 0;         
	for (ll i = 2; i < ns; i++) if (bs[i]) {
		for(ll j = i*i; j < ns; j += i) 
			bs[j] = 0;
		primes.push_back(i);  
	} 
}
                       
bool isPrime(ll N) {
	if(N < ns) 
		return bs[N];
		
	for(int i = 0; (i < (int)primes.size()) && (primes[i]*primes[i] <= N); i++)
		if (N%primes[i] == 0) 
			return false;

	return true;                    
}

vector<ll> primeFactors(ll N) {   
	vector<ll> factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while( (N != 1LL) && (PF*PF <= N) ) { 
		while(N%PF == 0LL) { 
			N /= PF; 
			factors.push_back(PF); 
		}
		PF = primes[++PF_idx];                              
	}
	if(N != 1LL) factors.push_back(N);
	return factors;
}

vector<pii> primeFactorsPii(ll N) {   
	vector<pii> factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	
	while( (N != 1LL) && (PF*PF <= N) ) {
		pii p(PF, 0);
		while(N%PF == 0LL) { 
			N /= PF;
			p.second++; 
		}
		if(p.second > 0)	
			factors.push_back(p); 
		
		if((PF_idx+1) < (int)primes.size())
			PF = primes[++PF_idx];
	}
	if(N != 1LL) factors.push_back(pii(N, 1));
	return factors;
}

ll numPF(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
	while( (N != 1) && (PF*PF <= N) ){
		while(N%PF == 0){ 
			N /= PF;
			ans++;
		}
		PF = primes[++PF_idx];
	}
	return ans + (N != 1);
}

ll numDiffPF(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
	while ( (N != 1) && (PF*PF <= N)) {
		if(N%PF == 0) 
			ans++;                            
		while(N%PF == 0)
			N /= PF;
		PF = primes[++PF_idx];
	}	
	return ans + (N != 1);
}

ll sumPF(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
	while( (N != 1) && (PF*PF <= N)){
		while(N%PF == 0){ 
			N /= PF; 
			ans += PF; 
		}
		PF = primes[++PF_idx];
	}	
	return ans + (N != 1) * N;
}

ll numDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while ( (N != 1) && (PF*PF <= N) ){
		ll power = 0;                             
		while(N%PF == 0){ 
			N /= PF;
			power++; 
		}
		ans *= (power+1);                         
		PF = primes[++PF_idx];
	}
	return (N != 1) ? 2*ans : ans;    
}

ll powFast(ll x, ll e){
	if(e == 0)
		return 1LL;
	if(e == 1)
		return x;
		
	ll ans = powFast(x, e/2);
	ans = ans*ans;
	if(e&1) ans *= x;

	return ans;
}

ll sumDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while( (N != 1) && (PF*PF <= N) ) {
		ll power = 0;
		while(N%PF == 0){ 
			N /= PF; 
			power++; 
		}
		ans *= ((powFast(PF, power+1LL) - 1LL) / (PF-1LL)); // formula
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((powFast(N, 2LL) - 1LL) / (N-1LL));
	return ans;
}

ll EulerPhi(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;
	while( (N != 1) && (PF * PF <= N) ) {
		if (N % PF == 0) 
			ans -= ans / PF;         
		while(N % PF == 0) 
			N /= PF;
		PF = primes[++PF_idx];
  }
  return (N != 1) ? (ans - ans/N) : ans;
}

int eulerPhi[1000010];
void sieveEulerPhi(ll l) {
	for(int i=1; i<=l; i++)
		eulerPhi[i] = i;		
	for(int i = 0; (i < (int)primes.size()) && (primes[i] <= l); i++){
		for(ll j = primes[i]; j <= l; j += primes[i]) 
			eulerPhi[j] -= eulerPhi[j]/primes[i];
	} 
}

int mobius[1000010];
void sieveMobius(ll l) {
	mobius[1] = 1;
	for(int i=2; i<=l; i++)
		mobius[i] = 0;								
	for(int i = 0; (i < (int)primes.size()) && (primes[i] <= l); i++){
		for(ll j = primes[i]; j <= l; j += primes[i]){
			if(mobius[j] != -1){
				mobius[j]++;
				if(j%(primes[i]*primes[i]) == 0)
					mobius[j] = -1;
			}				
		}
	} 
	
	for(int i=2; i<=l; i++){
		if(mobius[i] == -1)
			mobius[i] = 0;
		else if(mobius[i]%2 == 0)
			mobius[i] = 1;			
		else
			mobius[i] = -1;						
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(1000020);
	sieveEulerPhi(1000000);
	sieveMobius(1000000);
	cout << "EulerPhi" << endl;
	for(int i=1; i<=36; i++){
		cout << i << " " << eulerPhi[i] << endl;
	}
	
	cout << endl;
	cout << "Mobius" << endl;
	for(int i=1; i<=36; i++){
		cout << i << " " << mobius[i] << endl;
	}
	
	return 0;
}
