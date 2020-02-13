#include <bits/stdc++.h>

using namespace std ;

int main(int argc, char const *argv[])
{
	pair <int, int> par ;
	int a, v, maior = 0, n = 1;
	cin >> a >> v ;

	// a variavel "maior" vai receber o maior indice de repeticao de um numero
	// ex: se o numero 1 for o que mais se repete e ele se repete 4 vezes
	// a variavel "maior" ira receber 4 

	while(a != 0 && v != 0)
	{
		int *vet = (int *) calloc(a+1, sizeof(int)) ;
		
		for(int i= 1; i<=a; i++) // precisa zerar o vetor
			vet[i] = 0; 
		
		for(int i = 1 ; i <= v ; i++)
		{

			// aqui eu recebo os valores de cada voo como se pede na questao
			cin >> par.first ;
			cin >> par.second ;

			// aqui eu conto quantas vezes cada numero se repete
			// toda vez que digitar 1, por exemplo, o vetor na posicao 1 ira ser incrementado
			// dessa maneira eu sei o indce de repeticao de cada aeroporto no caso
			vet[par.first] += 1 ;
			vet[par.second] += 1 ;


			// sempre que uma das posicoes do vetor for maior que a variavel "maior", a mesma ira receber o valor do vetor
			// a variavel "maior" vai receber o maior indice de repeticao de um numero
			// ex: se o numero 1 for o que mais se repete e ele se repete 4 vezes
			// a variavel "maior" ira receber 4 
			if(vet[par.first] > maior)
				maior = vet[par.first] ;
				
			if(vet[par.second] > maior) // esse tem que ser idependente do de cima
				maior = vet[par.second] ;

			//cout << maior << endl ;
		}
		//cout << "maior: " << maior << endl ;
		cout << "Teste " << n << endl ; // o 'T' de teste e em caixa alta 'Teste'

		for(int i = 1 ; i <= a ; i++)
		{
			//cout << "posicao "<< i << " eh " << vet[i] << endl ;
			//cout << vet[i] << endl ;
			if(vet[i] == maior){
				cout << i << " " ; // tava errada a forma de aprensentacao
			}
		}
		
		free(vet) ;
		maior = 0 ;
        n++ ;
        cout << endl << endl; //adicionei essa quebra de linha 
        
		cin >> a >> v ;
	}
	
	return 0;
}
