#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct C{
	long int x;
	long int y;
	
	C(){
		
	}
	C(long int a, long int b){
		x = a;
		y = b;
	}
};

stack<double> pilha;
stack<C> ponto;

C vetor[300010];

double coeficiente(C a, C b){
	return (a.y - b.y)/(double)(a.x - b.x);
}

bool compara(C a, C b){
	
	return a.x < b.x;
}

int main(){	
	long int n;
	double angulo;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> n;
	
	for(long int i=0; i<n; i++){
		cin >> vetor[i].x;
		cin >> vetor[i].y;
	}
	
	sort(vetor, vetor + n, compara);

	angulo = coeficiente(vetor[0], vetor[1]);	
	pilha.push(angulo);
	ponto.push(vetor[0]);
	
	for(long int i=2; i<n; i++){
		C ultimo = vetor[i-1];
		
		angulo = coeficiente(vetor[i], ultimo);
		while( !pilha.empty() && (angulo >= pilha.top()) ){
			ultimo = ponto.top();
			angulo = coeficiente(vetor[i], ultimo);			
			
			pilha.pop();
			ponto.pop();
		}
		
		pilha.push(angulo);
		ponto.push(ultimo);
	}
	
	cout << pilha.size() << endl;
		
	return 0;
}