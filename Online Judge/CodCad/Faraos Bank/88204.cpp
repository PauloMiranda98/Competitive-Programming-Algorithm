#include <iostream>
#include <algorithm>
#define MENOR -1000000001
#define MAX 100001

struct R{
	long int mPre;
	long int sPre;
	long int mSuf;
	long int sSuf;
	long int m;
	long int s;
	
	R(){
		m = MENOR;
	}
	
	R(long int _m, long int _s){
		m = _m;
		s = _s;		
		mPre = _m;
		sPre = _s;
		mSuf = _m;
		sSuf = _s;		
	}		
	
	R(long int _m, long int _s, long int _ms, long int _ss, long int _mp, long int _sp){
		m = _m;
		s = _s;
		mPre = _mp;
		sPre = _sp;
		mSuf = _ms;
		sSuf = _ss;		
	}		
};

R arvore[4*MAX];
long int acao[MAX];
long int somaTotal[MAX];


R maximo(R a, R b){
	if(a.m == b.m){
		if( a.s > b.s)
			return a;
		else
			return b;
	}else if( a.m > b.m){
		return a;
	}else{
		return b;		
	}
}

void construir(long int no, long int i , long int j){
	if(i == j){
		arvore[no] = R(acao[i], 1);
		return;
	}
	
	long int esquerda = 2*no;      // indice do filho da esquerda
	long int direita  = 2*no + 1;  // indice do filho da direita
	
	long int m = (i+j)/2;
	
	construir(esquerda, i, m);
	construir(direita, m+1, j);
	
	R r_e = arvore[esquerda];
	R r_d = arvore[direita];
	
	long int mPre, sPre, mSuf, sSuf;
	
	//Prefixo	
	if(r_e.mPre > (r_d.mPre + somaTotal[m] - somaTotal[i-1]) ){
		mPre = r_e.mPre;
		sPre = r_e.sPre;
	}else{
		mPre = r_d.mPre + somaTotal[m] - somaTotal[i-1];
		sPre = r_d.sPre + m - i + 1;		
	}
	
	//Sufixo	
	if(r_d.mSuf > (r_e.mSuf + somaTotal[j] - somaTotal[m]) ){
		mSuf = r_d.mSuf;
		sSuf = r_d.sSuf;
	}else{
		mSuf = r_e.mSuf + somaTotal[j] - somaTotal[m];
		sSuf = r_e.sSuf + j - m;
	}
	
	R res = maximo( R(r_e.mSuf+r_d.mPre, r_e.sSuf + r_d.sPre) , maximo(r_e, r_d) );
	res.mPre = mPre;
	res.mSuf = mSuf;
	
	res.sPre = sPre;				
	res.sSuf = sSuf;
	
	arvore[no] = res;
}

R consulta(long int no, long int i, long int j, long int A, long int B){
	
	if(A <= i && j <= B){ // primeiro caso: [i, j] esta contido em [A, B]
		return arvore[no];
	}
	
	if(i > B || A > j){ // segundo caso: [i, j] e [A, B] sao disjuntos (ou i > j, que significa um no invalido)
		return R(MENOR, 0);
	}
	
	// terceiro caso: chamaremos a funcao nos dois filhos e retornaremos a melhor resposta
	long int esquerda = 2*no;      // indice do filho da esquerda
	long int direita  = 2*no + 1;  // indice do filho da direita
	
	long int meio = (i + j)/2;
	
	// calculamos a resposta para cada filho
	R r_e = consulta(esquerda, i, meio, A, B);
	R r_d  = consulta(direita, meio+1, j, A, B);

	
	if(r_e.m == MENOR) return r_d;
	if(r_d.m == MENOR) return r_e;
		
	long int mPre, sPre, mSuf, sSuf;
	
	//Prefixo	
	if(r_e.mPre > (r_d.mPre + somaTotal[meio] - somaTotal[i-1]) ){
		mPre = r_e.mPre;
		sPre = r_e.sPre;
	}else{
		mPre = r_d.mPre + somaTotal[meio] - somaTotal[i-1];
		sPre = r_d.sPre + meio - i + 1;		
	}
	
	//Sufixo	
	if(r_d.mSuf > (r_e.mSuf + somaTotal[j] - somaTotal[meio]) ){
		mSuf = r_d.mSuf;
		sSuf = r_d.sSuf;
	}else{
		mSuf = r_e.mSuf + somaTotal[j] - somaTotal[meio];
		sSuf = r_e.sSuf + j - meio;
	}
	
	R res = maximo( R(r_e.mSuf+r_d.mPre, r_e.sSuf + r_d.sPre) , maximo(r_e, r_d) );
	res.mPre = mPre;
	res.mSuf = mSuf;
	
	res.sPre = sPre;				
	res.sSuf = sSuf;
				
	return res;
		
}

using namespace std;

int main(){
	
	long int n, k, t;	
	long int x, y;
	R res;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> t;
	
	while(t--){
		somaTotal[0] = 0;
		cin >> n;
				
		for(long int i = 1; i <= n; i++){
			cin >> acao[i];
			somaTotal[i] = somaTotal[i-1] + acao[i];
		}
		
		construir(1, 1, n);
		
		cin >> k;
			
		for(long int i = 1; i <= k; i++){
			cin >> x >> y;
			res = consulta(1, 1, n, x, y);
			cout << res.m << " " << (res.s) << endl;
		}
		
	}
		
	return 0;
}