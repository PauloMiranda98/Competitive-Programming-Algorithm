#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll qtd;

map<ll, ll> mapa;

void inserir(ll p, ll n){
	mapa[p] += n;
	qtd += n;
}

void remover(ll n){
	ll k = qtd - n;
		
	while(k > 0LL){				
		auto par = mapa.end();
		par--;
		
		if( par->second <= k){
			qtd -= par->second;
			k -= par->second;
			
			mapa.erase(par);			
		}else{
			par->second -= (k);			
			qtd -= k;
			k = 0;
		}
	}
}

ll pegar(ll k){
	ll res = 0;
	
	while(k > 0LL){				
		auto par = mapa.begin();
		
		if(par == mapa.end()){
			return -1LL;
		}
		
		if( par->second <= k){
			res += (par->first) * (par->second); 			
			qtd -= par->second;
			k -= par->second;
						
			mapa.erase(par);			
		}else{
			res += (par->first)*k;
			qtd -= k;
			par->second -= k;			
			
			k = 0;			
		}
	}
	
	return res;
}

ll c[100100];
ll b[100100];
ll p[100100];

int main(int argc, char** args){
	int n;
	
	cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> c[i] >> b[i] >> p[i];
	
	ll res = 0LL;
	
	for(int i=0; i<n; i++){
		remover(c[i]);
		inserir(p[i], b[i]);
		
		ll aux = pegar(c[i]);
		
		if(aux == -1LL){
			cout << -1 << endl;
			
			return 0;
		}
		
		res += aux;			
	}
	
	cout << res << endl;
		
	return 0;
}
