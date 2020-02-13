






#include <iostream>

using namespace std;

int main(){   	
   	int vetor[100000], n = 0, soma = 0, s = 0, i = 0;
   	
   	cin >> n;
   	
   	for(i=0; i < n; i++){
		cin >> vetor[i];
		
		soma = soma + vetor[i];	  	   
	}
	
	soma = soma/2;
	
	i = 0;
	
	while(s != soma){
		s = s + vetor[i];
		
		i++;
	}
   	
   	cout << i << endl;
   	
	return 0;
}


