#include <iostream>
#include <algorithm>
#include <list>
#include <stdio.h>

using namespace std;

typedef struct {
	int i,f;
} Lista;

Lista lista[1000001];

int compare(Lista a, Lista b){
	
	return a.i > b.i; 
}

int compare2(Lista a, Lista b){
	
	return a.f < b.f; 
}

int main(){
	
	int i, n, ultimo=0, cont=0;
	
	cin >> n;
	
	for(i=0; i < n; i++){
		scanf("%d %d", &lista[i].i, &lista[i].f);
	}

	sort(lista, lista + n, compare);		
	sort(lista, lista + n, compare2);	
	ultimo = 0;
	
	for(i=0; i < n; i++){
		cont = max(cont, ultimo + lista[i].i - lista[i].f);
		ultimo += lista[i].i;
	}
	
	cout << (cont) << endl;	    			 	
													 			   				
	return 0;
	
}   
   
