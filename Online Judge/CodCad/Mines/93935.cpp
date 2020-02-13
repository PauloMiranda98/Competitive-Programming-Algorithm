#include <iostream>

using namespace std;

long long int e_composto[1000010];

long long int crivo(long int n){
  long long int res = 0;
  
  e_composto[1] = 0; // 1 nao e composto, mas o vetor na verdade guarda os numeros que nao sao primos
  
  for(int i = 2; i <= n; ++i){
    if(e_composto[i] != 0LL){
 	   res += e_composto[i];
 	   
      for(int j = 2; j*i <= n; ++j){
        e_composto[i*j] = 0;
      }
    }
  }
  
  return res;
}

int main(){
  long int n;
  cin >> n;
  
  n = n/100;
  
  for(long int i = 1; i <= n; i++){
	  cin >> e_composto[i];
  }
  
  cout << crivo(n) << endl; 
  return 0;
}