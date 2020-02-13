#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

int valores[9];
int valores2[9];

bool achou[9];
bool usado[9];

int custo[87654322];

queue<string> fila;
set<int> testar;

void resultado(){	
	fila.push("12345678");
		
	custo[12345678] = 0;
	
	int principal;
	char swap;
	int x;				
	string valor;
	string u;
	int peso;
	
	while(!fila.empty()){
		u = fila.front();		
		principal = atoi(u.c_str());
		
		valor = u;
		
		if(valores[valor[0] - 48] == valores2[1] &&  valores[valor[1] - 48] == valores2[2]
		&& valores[valor[2] - 48] == valores2[3] &&  valores[valor[3] - 48] == valores2[4]
		&& valores[valor[4] - 48] == valores2[5] &&  valores[valor[5] - 48] == valores2[6]
		&& valores[valor[6] - 48] == valores2[7] &&  valores[valor[7] - 48] == valores2[8]){
			testar.insert(principal);
		}
		
		//0-1
		valor = u;
		
		swap = valor[0];
		valor[0] = valor[1];
		valor[1] = swap;
		
		peso = valores[valor[0] - 48] + valores[valor[1] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		
		//1-2
		valor = u;
		
		swap = valor[1];
		valor[1] = valor[2];
		valor[2] = swap;
		
		peso = valores[valor[1] - 48] + valores[valor[2] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		
		
		//2-3
		valor = u;
		
		swap = valor[2];
		valor[2] = valor[3];
		valor[3] = swap;
		
		peso = valores[valor[2] - 48] + valores[valor[3] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		

		//4-5
		valor = u;
		
		swap = valor[4];
		valor[4] = valor[5];
		valor[5] = swap;
		
		peso = valores[valor[4] - 48] + valores[valor[5] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		

		//5-6
		valor = u;
		
		swap = valor[5];
		valor[5] = valor[6];
		valor[6] = swap;
		
		peso = valores[valor[5] - 48] + valores[valor[6] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		
				

		//6-7
		valor = u;
		
		swap = valor[6];
		valor[6] = valor[7];
		valor[7] = swap;
		
		peso = valores[valor[6] - 48] + valores[valor[7] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		

		//0-4
		valor = u;
		
		swap = valor[0];
		valor[0] = valor[4];
		valor[4] = swap;
		
		peso = valores[valor[0] - 48] + valores[valor[4] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		
				

		//1-5
		valor = u;
		
		swap = valor[1];
		valor[1] = valor[5];
		valor[5] = swap;
		
		peso = valores[valor[1] - 48] + valores[valor[5] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		

		//2-6
		valor = u;
		
		swap = valor[2];
		valor[2] = valor[6];
		valor[6] = swap;
		
		peso = valores[valor[2] - 48] + valores[valor[6] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		
				

		//3-7
		valor = u;
		
		swap = valor[3];
		valor[3] = valor[7];
		valor[7] = swap;
		
		peso = valores[valor[3] - 48] + valores[valor[7] - 48];
		
		x = atoi(valor.c_str());
		if( (peso + custo[principal]) < custo[x] ){
			custo[x] = custo[principal] + peso;
			fila.push(valor);
		}		
		
		fila.pop();	
							
	}
}

int main() {
	
	int minimo = ~(1<<31);
	
	register int i;
	for(i=12345678 ; i<=87654321; i++)
		custo[i] = ~(1<<31);
	
	
	cin >> valores[1] >> valores[2] >> valores[3] >> valores[4];
	cin >> valores[5] >> valores[6] >> valores[7] >> valores[8];

	cin >> valores2[1] >> valores2[2] >> valores2[3] >> valores2[4];
	cin >> valores2[5] >> valores2[6] >> valores2[7] >> valores2[8];

	
	resultado();
	
	set<int>::iterator it;	
	
	for(it = testar.begin(); it!=testar.end(); it++)
		minimo = min(minimo, custo[*it]);
					
	cout << minimo << endl;
		
	return 0;
}
