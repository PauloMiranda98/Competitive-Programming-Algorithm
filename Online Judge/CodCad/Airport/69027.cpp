#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main(void) {
	
	int x=1, a, v;
	
	scanf("%d %d", &a, &v);
	
	while(a && v){
		
		int i, y, z, maior=0;
		int lista[101];
		
		memset(lista, 0, sizeof(lista));
		
		for(i=0; i<v; i++){
			scanf("%d %d", &y, &z);
			lista[y]++;
			lista[z]++;
		}
						
		for(i=0; i<=a; i++){
		   if(lista[i] > maior)
			  maior = lista[i];	
		}

		cout << "Teste " << x << endl;
		for(i=0; i<=a; i++){
			if(lista[i] == maior)
 	  	  	  cout << i << " ";	
		}
		
		cout << endl<<endl;
		
		x++;
		scanf("%d %d", &a, &v);
	}

    return 0;
}


