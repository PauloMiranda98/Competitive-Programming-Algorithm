#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


map<long int, long int> conteiner;

struct Caixa{
	long int p;
	long int r;
	long int n;	
	
	Caixa(){
		r = 0;
		p = 10000010;
		n = 1;
	}
	
	Caixa(long int a, long int b, long int c){
		p = a;
		r = b;
		n = c;
	}
};

bool compara(Caixa a, Caixa b){
	if(a.r == b.r){
		return a.p > a.p;
	}
	
	return a.r > b.r;
}

vector<Caixa> vetor;

int main(){
	long int res = 0;
	long int n;
	cin >> n;
	
	vetor.resize(n);
	
	for(long int i=0; i < n; i++){
		cin >> vetor[i].p;
		cin >> vetor[i].r;
		
		if(vetor[i].p > vetor[i].r){
			i--;
			n--;
			vetor.pop_back();
		}
	}
	
	sort(vetor.begin(), vetor.end(), compara);
	
	vetor.resize(2*n);
	
	if(n > 1)
		res = 1;
		
	for(long int i=n-2; i >= 0; i--){
		vector<Caixa> aux;
		
		for(int j = i+1; j < n+res-1; j++){
			Caixa c(vetor[i].p + vetor[j].p, vetor[i].r, vetor[i].n + vetor[j].n);
			
			if( (c.p)<= vetor[i].r ){
				aux.push_back(c);				
			}
		}
		
		for(long int j = 0; j < (long int) aux.size(); j++){
			if(aux[j].p < vetor[n-1 + aux[j].n -1].p)
				vetor[n-1 + aux[j].n -1] = aux[j];
				
			if(aux[j].n > res)
				res = aux[j].n;
		}
	}
	
	cout << res << endl;
		
	return 0;
}